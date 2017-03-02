#!/usr/bin/env python3
import sys

def quit(reason):
    if reason == 1:
        print('Usage: ./caesar n\nWhere n is non-negative value.')
    elif reason == 2:
        print('Wrong value!')
    sys.exit(reason)

big = ('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
       'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
       'W', 'X', 'Y', 'Z')

small = tuple([x.lower() for x in big])

if __name__ == '__main__':
    if len(sys.argv) != 2:
        quit(1)
    
    try:
        shift = int(sys.argv[1]) % 26
        if shift < 0:
            int('a')
    except ValueError:
        quit(2)
    
    plaintext = input('plaintext: ')
    print('ciphertext: ', end='')
    for char in plaintext:
        if char in big:
            index = (big.index(char) + shift) % 26
            print(big[index], end='')
        elif char in small:
            index = (small.index(char) + shift) % 26
            print(small[index], end='')
        else:
            print(char, end='')
    print()