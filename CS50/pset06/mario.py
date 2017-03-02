def get_h(inp):
    try:
        temp = int(input(inp))
        return temp if temp > -1 and temp < 24 else get_h("Height: ")
    except:
        return get_h("Retry: ")

h = get_h("Height: ")

for x in range(1, h + 1):
    print(''.join([' ' for n in range(h - x)] + ['#' for n in range(x)] + [' '] + ['#' for n in range(x)]))