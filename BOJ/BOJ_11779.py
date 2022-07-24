

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def solution(st, ed):
    global n, g
    inf = 100000*100000
    dist = [inf for _ in range(n)]
    visit = [False for _ in range(n)]
    from_ = [-1 for _ in range(n)]
    dist[st] = 0

    selected = st
    while selected != ed:
        visit[selected] = True
        for (to, cost) in g[selected]:
            #dist[to] = min(dist[to], dist[selected]+cost)
            if dist[selected]+cost < dist[to]:
                from_[to] = selected
                dist[to] = dist[selected]+cost
        # select
        min_dist = inf
        for (i, d) in enumerate(dist):
            if visit[i]:
                continue
            if d < min_dist:
                min_dist = d
                selected = i

    route = []
    prev = ed
    while prev != -1:
        route.append(prev)
        prev = from_[prev]

    route.reverse()
    route = list(map(lambda x: x+1, route))
    return (dist[ed], route)


n = int(read())
m = int(read())
g = [[] for _ in range(n)]

for _ in range(m):
    fr, to, cost = map(int, read().split())
    g[fr-1].append((to-1, cost))

x, y = map(int, read().split())

(cost, route) = solution(x-1, y-1)
route = list(map(str, route))

print(cost)
print(len(route))
print(' '.join(route))
