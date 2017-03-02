def get_h(inp):
    try:
        temp = int(input(inp))
        return temp if temp > -1 and temp < 24 else get_h("Height: ")
    except:
        return get_h("Retry: ")

h = get_h("Height: ")

for x in range(2, h + 2):
    print(''.join([' ' for n in range(h - x + 1)] + ['#' for n in range(x)]))