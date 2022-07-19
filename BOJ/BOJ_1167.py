
import sys


def read():
    return sys.stdin.readline().rstrip()


def dfs(node, dist):
    global g, visit, max_info
    visit[node] = True

    if max_info[1] < dist:
        max_info = (node, dist)

    for (next, next_dist) in g[node]:
        if not visit[next]:
            dfs(next, dist+next_dist)


V = int(read())
g = [[] for _ in range(V)]
visit = [False for _ in range(V)]

max_info = (-1, 0)  # node, dist

for _ in range(V):
    info = list(map(int, read().split()))
    u = info[0]-1
    for i in range(1, len(info), 2):
        if info[i] == -1:
            break
        v = info[i] - 1
        weight = info[i+1]
        g[u].append((v, weight))
        g[v].append((u, weight))

dfs(0, 0)
visit = [False for _ in range(V)]
dfs(max_info[0], 0)

print(max_info[1])
