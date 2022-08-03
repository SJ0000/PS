

import sys


def read():
    return sys.stdin.readline().rstrip()


def find(u):
    if u == parent[u]:
        return u
    parent[u] = find(parent[u])
    return parent[u]


def union(u, v):
    u = find(u)
    v = find(v)
    if u == v:
        return
    parent[v] = u


N = int(read())
M = int(read())
g = []
for _ in range(N):
    g.append(list(map(int, read().split())))
plan = list(map(lambda x: int(x)-1, read().split()))

parent = [i for i in range(N)]
for i in range(N):
    for j in range(N):
        if g[i][j] == 1:
            union(i, j)

answer = "YES"
start = plan[0]
for i in range(1, M):
    if find(start) != find(plan[i]):
        answer = "NO"
        break
print(answer)
