

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


# 외부공기 2, 내부공기 0, 치즈 1
INSIDE_AIR = 0
CHEESE = 1
OUTSIDE_AIR = 2


def melt(a, cheese):
    checks = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    melt_positions = []
    for (x, y) in cheese:
        air = 0
        for (dx, dy) in checks:
            ax = x+dx
            ay = y+dy
            if a[ax][ay] == OUTSIDE_AIR:
                air += 1
            if air == 2:
                break
        if air == 2:
            melt_positions.append((x, y))

    for (x, y) in melt_positions:
        cheese.discard((x, y))
        a[x][y] = 0


def inject_air(a):
    n = len(a)
    m = len(a[0])
    visit = [[False for _ in range(m)] for __ in range(n)]
    moves = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    q = deque()
    q.append((0, 0))
    visit[0][0] = True

    while len(q) > 0:
        (x, y) = q.popleft()
        for (dx, dy) in moves:
            ax = x+dx
            ay = y+dy
            if not (0 <= ax < n and 0 <= ay < m):
                continue
            if visit[ax][ay] or a[ax][ay] == CHEESE:
                continue
            q.append((ax, ay))
            visit[ax][ay] = True
            a[ax][ay] = OUTSIDE_AIR


n, m = map(int, read().split())

a = []
for _ in range(n):
    a.append(list(map(int, read().split())))

cheese = set()
for i in range(n):
    for j in range(m):
        if a[i][j] == 1:
            cheese.add((i, j))

time = 0

while len(cheese) > 0:
    inject_air(a)
    melt(a, cheese)
    time += 1

print(time)
