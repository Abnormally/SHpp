#!/usr/bin/env python3
import sys

def quit(reason):
    if reason == 1:
        print('Usage: ./vigenere [code_string]')
    elif reason == 2:
        print('Code string must contain only alphabetical characters!')
    sys.exit(reason)

if __name__ == '__main__':
    pass