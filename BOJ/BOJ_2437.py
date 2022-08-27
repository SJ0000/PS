
from collections import deque
import heapq

import sys


def read():
    return sys.stdin.readline().rstrip()


def solution(a):
    if a[0] > 1:
        return 1

    possible_last = 1
    for i in range(1, len(a)):
        if a[i] > possible_last+1:
            break
        possible_last += a[i]
    return possible_last+1


N = int(read())
a = list(map(int, read().split()))
a.sort()

print(solution(a))
