
from collections import deque
import heapq

import sys


def read():
    return sys.stdin.readline().rstrip()


pq = list()

N, M = map(int, read().split())
a = list(map(int, read().split()))
for item in a:
    heapq.heappush(pq, item)

for _ in range(M):
    x = heapq.heappop(pq)
    y = heapq.heappop(pq)
    heapq.heappush(pq, x+y)
    heapq.heappush(pq, x+y)

print(sum(pq))
