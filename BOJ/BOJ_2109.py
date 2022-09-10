
from collections import deque
from heapq import heappop, heappush
import sys


def read():
    return sys.stdin.readline().rstrip()


n = int(read())
pays = [[] for _ in range(10000)]
for _ in range(n):
    p, d = map(int, read().split())
    pays[d-1].append(-p)

total_pay = 0
pq = []
for day in range(9999, -1, -1):
    for p in pays[day]:
        heappush(pq, p)
    if len(pq) > 0:
        total_pay += -heappop(pq)

print(total_pay)
