
from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def reverse(x):
    return list(reversed(x))


s = list(read())
t = list(read())

while len(s) != len(t):
    if t[-1] == 'A':
        t.pop()
    else:
        t.pop()
        t = reverse(t)

print(1 if s == t else 0)
