
from collections import deque
import heapq

import sys


def read():
    return sys.stdin.readline().rstrip()


N = int(read())
a = []
for _ in range(N):
    a.append(int(read()))
a.sort(reverse=True)

answer = 0
seq = 1
for i in range(N):
    tip = a[i]-(seq-1)
    if tip <= 0:
        continue
    answer += tip
    seq += 1

print(answer)
