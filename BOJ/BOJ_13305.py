
from collections import deque

import sys


def read():
    return sys.stdin.readline().rstrip()


def find_next(current):
    next_dist = 0
    for i in range(current+1, N):
        next_dist += dist[i-1]
        if price[current] > price[i]:
            return (i, next_dist)

    return (N-1, next_dist)


N = int(read())
dist = list(map(int, read().split()))
price = list(map(int, read().split()))

used = 0
current = 0
while current < N-1:
    (next, next_dist) = find_next(current)
    used += price[current]*next_dist
    current = next

print(used)
