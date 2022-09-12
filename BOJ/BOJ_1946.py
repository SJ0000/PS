
from collections import deque
from heapq import heappop, heappush
import sys


def read():
    return sys.stdin.readline().rstrip()


def solution():
    n = int(read())
    doc = []
    interview = []
    for i in range(n):
        x, y = map(int, read().split())
        doc.append(x)
        interview.append((y, i))
    interview.sort()

    cut = doc[interview[0][1]]
    result = 1

    for i in range(1, n):
        current = interview[i][1]
        if doc[current] > cut:
            continue
        cut = doc[current]
        result += 1
    print(result)


T = int(read())
for _ in range(T):
    solution()
