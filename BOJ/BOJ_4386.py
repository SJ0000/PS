

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def get_dist(p1, p2):
    (x1, y1) = p1
    (x2, y2) = p2
    return ((abs(x1-x2)**2)+(abs(y1-y2)**2))**0.5


def find(u):
    if parent[u] == u:
        return u
    parent[u] = find(parent[u])
    return parent[u]


def union(u, v):
    global parent
    u = find(u)
    v = find(v)
    parent[u] = v


n = int(read())

parent = [i for i in range(n)]
points = []
for _ in range(n):
    x, y = map(float, read().split())
    points.append((x, y))

edges = []

for i in range(n-1):
    for j in range(i+1, n):
        dist = get_dist(points[i], points[j])
        edges.append((dist, i, j))

edges.sort()
cost = 0
for i in range(len(edges)):
    (dist, u, v) = edges[i]
    if find(u) == find(v):
        continue
    union(u, v)
    cost += dist

print(cost)
