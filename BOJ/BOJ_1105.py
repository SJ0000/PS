
from collections import deque

import sys


def read():
    return sys.stdin.readline().rstrip()


def solution(l, r):
    if len(l) != len(r):
        return 0
    n = len(l)
    count = 0
    for i in range(n):
        if l[i] != r[i]:
            break
        if l[i] == '8':
            count += 1

    return count


L, R = read().split()

print(solution(L, R))
