

from curses.ascii import isalpha
import sys


def read():
    return sys.stdin.readline().rstrip()


def process(li):
    result = ''
    st = []
    priority = {'*': 2, '/': 2, '+': 1, '-': 1, '(': 0}

    for ch in li:
        if isalpha(ch):
            result += ch
        elif ch == '(':
            st.append(ch)
        elif ch == ')':
            while len(st) > 0 and st[-1] != '(':
                result += st.pop()
            st.pop()
        else:
            while len(st) > 0 and priority[ch] <= priority[st[-1]]:
                result += st.pop()
            st.append(ch)

    while len(st) > 0:
        result += st.pop()

    print(result)


x = read()

process(list(x))
