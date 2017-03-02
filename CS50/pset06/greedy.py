#!/usr/bin/env python3

def get_float():
    result = 1.0
    try:
        result = float(input())
    except:
        print('Retry: ', end='')
        result = get_float()
    return result

if __name__ == '__main__':
    coins = (25, 10, 5, 1)
    income = -1
    print('O hai! ', end='')
    while income < 0:
        print('How much change is owed?')
        income = round(get_float() * 100)
    
    coin = 0
    for c in coins:
        coin += income // c
        income %= c
    
    print(coin)