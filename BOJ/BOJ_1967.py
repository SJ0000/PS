

import sys


def read():
    return sys.stdin.readline().rstrip()


n = int(read())

g = [set() for _ in range(n)]
diameters = [[] for _ in range(n)]
from_leaf = [0 for _ in range(n)]  # leaf ~ 자신까지의 최대 길이
indegree = [0 for _ in range(n)]
for _ in range(n-1):
    x, y, w = map(int, read().split())
    g[y-1].add((x-1, w))
    indegree[x-1] += 1


while True:
    changed = False
    remove = []
    for i in range(n):
        if indegree[i] == 0:
            for (parent, w) in g[i]:
                from_leaf[parent] = max(from_leaf[i] + w, from_leaf[parent])
                diameters[parent].append(from_leaf[i]+w)
                remove.append((i, parent, w))
                changed = True
                indegree[parent] -= 1

    for (x, y, w) in remove:
        g[x].discard((y, w))

    if not changed:
        break

answer = 0
for i in range(n):
    if len(diameters[i]) == 0:
        continue
    if len(diameters[i]) == 1:
        answer = max(answer, diameters[i][0])
        continue
    diameters[i].sort(reverse=True)
    answer = max(answer, diameters[i][0] + diameters[i][1])
print(answer)
