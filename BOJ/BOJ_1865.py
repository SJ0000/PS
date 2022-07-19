

import sys


def read():
    return sys.stdin.readline().rstrip()

# 풀이 보고 풀었음
# https://www.acmicpc.net/board/view/72995


def solution():
    n, m, w = map(int, read().split())
    dist = [0 for _ in range(n)]
    edges = dict()
    for _ in range(m):
        s, e, t = map(int, read().split())
        s -= 1
        e -= 1
        if (s, e) in edges:
            edges[(s, e)] = min(edges[(s, e)], t)
            edges[(e, s)] = min(edges[(e, s)], t)
        else:
            edges[(s, e)] = t
            edges[(e, s)] = t
    for _ in range(w):
        s, e, t = map(int, read().split())
        s -= 1
        e -= 1
        if (s, e) in edges:
            edges[(s, e)] = min(edges[(s, e)], -t)
        else:
            edges[(s, e)] = -t

    # 벨만 포드 알고리즘
    # 모든 정점이 동시에 출발 (dist[모든 정점]=0)

    for _ in range(n-1):
        for (u, v) in edges.keys():
            weight = edges[(u, v)]
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u]+weight

    copy = dist[:]
    for (u, v) in edges.keys():
        weight = edges[(u, v)]
        if dist[u] + weight < dist[v]:
            dist[v] = dist[u]+weight

    for (x, y) in zip(dist, copy):
        if x != y:
            print("YES")
            return
    print("NO")


tc = int(read())
for _ in range(tc):
    solution()
