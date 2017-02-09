#!/usr/bin/env python3
def get_card():
    result = input()
    try:
        temp = int(result)
        if temp < 0:
            int('a')
    except ValueError:
        print('Retry: ', end='')
        result = get_card()
    return result

def checker(num, first, second):
    print(num, first, second)
    if num == 0:
        print('passed 0')
        if first == 3:
            return 1
        elif first == 5 and second == 5:
            return 3
        elif first == 4 and second == 2:
            return 2
    elif num == 7:
        print('passed 7')
        if first == 4:
            return 2
    elif num == 5:
        print('passed 5')
        if first == 5 and second == 1:
            return 3
    return 0

if __name__ == '__main__':
    cards = ('INVALID', 'AMEX', 'VISA', 'MASTERCARD')
    print('Number: ', end='')
    card = get_card()
    l = len(card)
    if 12 < l < 17 and '2' < card[0] < '6':
        i_card = [int(x) for x in card]
        esum = 0
        for x in i_card[1::2]:
            x *= 2
            if x > 9:
                x = (x % 10) + (x // 10)
            esum += x
        osum = sum(i_card[::2])
        
        check1 = (osum + esum) % 10
        print(cards[checker(check1, i_card[0], i_card[1])])
    else:
        print(cards[0])