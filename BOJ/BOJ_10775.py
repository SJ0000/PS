

import sys


def read():
    return sys.stdin.readline().rstrip()


def union(u, v):
    u = find(u)
    v = find(v)
    if u == v:
        return
    gate[u] = v


def find(u):
    if u == gate[u]:
        return u
    gate[u] = find(gate[u])
    return gate[u]


G = int(read())
P = int(read())

gate = [i for i in range(G+1)]

closed = False
answer = 0
for _ in range(P):
    x = int(read())
    if closed:
        continue
    x = find(x)
    if x == 0:
        closed = True
        continue
    union(x, x-1)
    answer += 1

print(answer)
