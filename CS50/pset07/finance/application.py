from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from passlib.apps import custom_app_context as pwd_context
from tempfile import gettempdir

from helpers import *

# configure application
app = Flask(__name__)

# ensure responses aren't cached
if app.config["DEBUG"]:
    @app.after_request
    def after_request(response):
        response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
        response.headers["Expires"] = 0
        response.headers["Pragma"] = "no-cache"
        return response

# custom filter
app.jinja_env.filters["usd"] = usd

# configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = gettempdir()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.route("/")
@login_required
def index():
    user = db.execute("SELECT * FROM users WHERE id = :ido", ido = session['user_id'])[0]
    bids = db.execute("SELECT * FROM bids WHERE user_id = :ido", ido = session['user_id'])
    string = ""
    summ = 0
    
    for x in bids:
        newprice = lookup(x['symbol'])['price']
        string += "<tr>\n\t<td>{0}</td>\n<td>{1}</td>\n<td>{2}</td>\n<td>{3}</td>\n<td>{4}</td>\n<td>{5}</td>\n</tr>\n".format(x['symbol'], x['name'], x['shares'], usd(x['bid_price']), usd(newprice), usd(x['shares'] * x['bid_price']))
        summ += (x['shares'] * newprice)
    
    return render_template("index.html", usermoney = usd(user['cash'] + summ), shares = string, cash = usd(user['cash']))

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock."""
    if request.method == "POST":
        sym = lookup(request.form.get("symbol"))
        
        if not sym:
            return apology("No such symbol here: ", request.form.get("symbol"))
        else:
            minprice = sym['price'] * int(request.form.get("shares"))
            usermoney = db.execute("SELECT * FROM users WHERE id = :ido", ido = session["user_id"])[0]['cash']
            if minprice > usermoney:
                return apology("Need more minerals! Needed: {0}".format(usd(minprice)), 'Minerals left: {0}'.format(usd(usermoney)))
            else:
                usermoney -= minprice
                bids = db.execute("SELECT * FROM bids WHERE user_id = :ido AND symbol = :syma", ido = session["user_id"], syma = sym['symbol'])
                if not bids:
                    db.execute('INSERT INTO bids (user_id, symbol, name, shares, bid_price) VALUES (:user, :syma, :name, :shares, :bid_price)',
                    user = session["user_id"], syma = sym['symbol'], name = sym['name'], shares = int(request.form.get("shares")), bid_price = sym['price'])
                else:
                    db.execute('UPDATE bids SET shares = :shares, bid_price = :bid_price WHERE user_id = :ido AND symbol = :syma',
                    shares = bids[0]['shares'] + int(request.form.get("shares")), bid_price = (bids[0]['bid_price'] + sym['price']) / 2, ido = session['user_id'],
                    syma = sym['symbol'])
            db.execute('UPDATE users SET cash = :cash WHERE id = :ido', cash = usermoney, ido = session["user_id"])
            
            return redirect(url_for("index"))
    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions."""
    h = db.execute('SELECT * FROM history WHERE user_id = :ido', ido = session["user_id"])
    return render_template("history.html", table = h)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in."""

    # forget any user_id
    session.clear()

    # if user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # query database for username
        rows = db.execute("SELECT * FROM users WHERE email = :email", email = request.form.get("email"))

        # ensure username exists and password is correct
        if len(rows) != 1 or not pwd_context.verify(request.form.get("password"), rows[0]["hash"]):
            return apology("invalid username and/or password")

        # remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # redirect user to home page
        return redirect(url_for("index"))

    # else if user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out."""

    # forget any user_id
    session.clear()

    # redirect user to login form
    return redirect(url_for("login"))

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        sym = lookup(request.form.get("symbol"))
        
        if not sym:
            return apology("No such symbol here: ", request.form.get("symbol"))
        else:
            return render_template("quoted.html", symbol = "<p share>A share of {0} ({1}) costs <strong>{2}</strong></p>".format(sym['name'], sym['symbol'], usd(sym['price'])))
    else:
        return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user."""
    session.clear()
    
    if request.method == "POST":
        
        if request.form.get("username"):
            name = request.form.get("username")
        else:
            name = request.form.get("email").split('@')[0]
        
        if not db.execute("SELECT * FROM users WHERE email = :email", email = request.form.get("email").lower()):
            session["user_id"] = db.execute("INSERT INTO users (email, username, hash) VALUES (:email, :username, :hasha)",
            email=request.form.get("email").lower(), username=name, hasha=pwd_context.encrypt(request.form.get("password")))
        else:
            return apology("This mail already registered!", request.form.get("email"))
    else:
        return render_template("register.html")
    
    return redirect(url_for("index"))

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock."""
    if request.method == "POST":
        sym = lookup(request.form.get("symbol"))
        bids = db.execute("SELECT * FROM bids WHERE user_id = :ido AND symbol = :syma", ido = session["user_id"], syma = sym['symbol'])[0]
        
        if not bids:
            return apology("No such bid here!", request.form.get("symbol"))
        elif bids['shares'] < int(request.form.get("shares")):
            return apology("Have no shares for this transaction!", 'Shares left: {0}.'.format(bids['shares']))
        else:
            profit = sym['price'] * int(request.form.get("shares"))
            user = db.execute('SELECT * FROM users WHERE id = :ido', ido = session["user_id"])[0]
            
            if bids['shares'] == int(request.form.get("shares")):
                db.execute("DELETE * FROM bids WHERE user_id = :ido AND symbol = :syma", ido = session["user_id"], syma = sym['symbol'])
            else:
                db.execute("UPDATE bids SET shares = :shares WHERE user_id = :ido AND symbol = :syma",
                shares = bids['shares'] - int(request.form.get("shares")), ido = session["user_id"], syma = sym['symbol'])
        
            db.execute('UPDATE users SET cash = :cash WHERE id = :ido', cash = profit + user['cash'], ido = session["user_id"])
    else:
        return render_template("sell.html")
    
    return redirect(url_for("index"))
