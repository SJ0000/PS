
from collections import deque
from heapq import heappop, heappush
import sys


def read():
    return sys.stdin.readline().rstrip()


def solution(a):
    n = len(a)
    r = len(list(filter(lambda x: x == 'R', a)))
    b = n-r
    if r == 0 or b == 0:
        return 0
    front_r, rear_r, front_b, rear_b = 0, 0, 0, 0
    for i in range(n):
        if a[0] == 'R' and a[i] == 'R':
            front_r += 1
        elif a[0] == 'B' and a[i] == 'B':
            front_b += 1
        else:
            break
    for i in range(n-1, -1, -1):
        if a[-1] == 'R' and a[i] == 'R':
            rear_r += 1
        elif a[-1] == 'B' and a[i] == 'B':
            rear_b += 1
        else:
            break
    return min(r-front_r, r-rear_r, b-front_b, b-rear_b)


n = int(read())
a = list(read())

print(solution(a))
