
from collections import deque
import heapq

import sys


def read():
    return sys.stdin.readline().rstrip()


def fib():
    f = [0 for _ in range(50)]
    f[1] = 1
    for i in range(2, 50):
        f[i] = f[i-1]+f[i-2]
    return f


def find(value):
    global f
    for i in range(len(f)-1, -1, -1):
        if f[i] <= value:
            return f[i]


def solution(value):
    x = []
    while value != 0:
        fib_loe = find(value)
        x.append(fib_loe)
        value -= fib_loe
    x.reverse()
    return ' '.join(map(str, x))


f = fib()

N = int(read())
for _ in range(N):
    value = int(read())
    print(solution(value))
