

import sys


def read():
    return sys.stdin.readline().rstrip()


N, M = map(int, read().split())
MAX_COST = 10001
m = list(map(int, read().split()))
c = list(map(int, read().split()))
d = [[0 for _ in range(MAX_COST)] for __ in range(N)]

# d[i][j] = i번째까지 왔을때 비용 j로 얻을 수 있는 최대 메모리

for cost in range(c[0], MAX_COST):
    d[0][cost] = m[0]

for i in range(1, N):
    memory, cost = m[i], c[i]
    for j in range(MAX_COST):
        if j-cost >= 0:
            d[i][j] = max(d[i-1][j], d[i-1][j-cost]+memory)
        else:
            d[i][j] = d[i-1][j]

for cost in range(MAX_COST):
    if d[N-1][cost] >= M:
        print(cost)
        break
