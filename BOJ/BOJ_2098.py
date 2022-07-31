

import sys


def read():
    return sys.stdin.readline().rstrip()


def dfs(node, visit):
    global W, N, d, INF
    if visit == (1 << N) - 1:
        return W[node][0] if W[node][0] != 0 else INF

    if d[node][visit] != INF and d[node][visit] != -1:
        return d[node][visit]

    if d[node][visit] == -1:
        return INF

    for next in range(N):
        if next == node:
            continue
        if W[node][next] == 0:
            continue
        if visit & (1 << next) == 0:
            d[node][visit] = min(d[node][visit], dfs(
                next, visit | (1 << next)) + W[node][next])

    if d[node][visit] == INF:
        d[node][visit] = -1
        return INF

    return d[node][visit]


INF = 987654321
N = int(read())
W = []
d = [[INF for _ in range(2**N)] for __ in range(N)]
for _ in range(N):
    W.append(list(map(int, read().split())))

print(dfs(0, 1))
