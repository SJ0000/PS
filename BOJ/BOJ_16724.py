

import sys


def read():
    return sys.stdin.readline().rstrip()


def dfs(x, y, belong_id):
    global a, belong, next
    belong[x][y] = belong_id
    (dx, dy) = next[a[x][y]]
    ax, ay = x+dx, y+dy
    result = belong_id
    if belong[ax][ay] == -1:
        result = dfs(ax, ay, belong_id)
    else:
        belong[x][y] = belong[ax][ay]
        return belong[ax][ay]
    belong[x][y] = result
    return result


N, M = map(int, read().split())
a = []
for _ in range(N):
    a.append(list(read()))

belong = [[-1 for _ in range(M)] for __ in range(N)]
next = {"U": (-1, 0), "D": (1, 0), "L": (0, -1), "R": (0, 1)}

belong_id = 0
for i in range(N):
    for j in range(M):
        if belong[i][j] == -1:
            dfs(i, j, belong_id)
            belong_id += 1

s = set()
for i in range(N):
    for j in range(M):
        s.add(belong[i][j])
print(len(s))
