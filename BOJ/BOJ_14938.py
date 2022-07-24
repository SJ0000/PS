

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


INF = 987654321
n, m, r = map(int, read().split())
g = [[INF for _ in range(n)] for _ in range(n)]
items = list(map(int, read().split()))
for _ in range(r):
    a, b, l = map(int, read().split())
    if l < g[a-1][b-1]:
        g[a-1][b-1] = l
        g[b-1][a-1] = l
for i in range(n):
    g[i][i] = 0

for k in range(n):
    for u in range(n):
        if g[u][k] == INF:
            continue
        for v in range(n):
            g[u][v] = min(g[u][v], g[u][k] + g[k][v])

result = 0
for start in range(n):
    item_count = 0
    for field in range(n):
        if g[start][field] <= m:
            item_count += items[field]
    result = max(result, item_count)

print(result)
