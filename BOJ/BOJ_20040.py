

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def union(u, v):
    global parent
    u = find(u)
    v = find(v)
    if u == v:
        return
    if u < v:
        parent[u] = v
    else:
        parent[v] = u


def find(u):
    if u == parent[u]:
        return u

    childrens = [u]
    while u != parent[u]:
        u = parent[u]
        childrens.append(u)

    for child in childrens:
        parent[child] = u

    return u


n, m = map(int, read().split())

parent = [i for i in range(n)]

cycled = False
first_cycle_time = 0

for time in range(1, m+1):
    (u, v) = map(int, read().split())
    if cycled:
        union(u, v)
    else:
        if find(u) == find(v):
            cycled = True
            first_cycle_time = time
        union(u, v)

print(first_cycle_time)
