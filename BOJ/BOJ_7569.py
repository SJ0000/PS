

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def process():
    global a, H, N, M

    # H,N,M
    moves = [(1, 0, 0), (-1, 0, 0), (0, 1, 0),
             (0, -1, 0), (0, 0, 1), (0, 0, -1)]
    visit = [[[False for _ in range(M)] for __ in range(N)]
             for ___ in range(H)]

    target_exist = False
    q = deque()
    for i in range(H):
        for j in range(N):
            for k in range(M):
                if a[i][j][k] == 1:
                    visit[i][j][k] = True
                    q.append((i, j, k))
                if a[i][j][k] == 0:
                    target_exist = True

    if target_exist == False:
        return 0

    days = 0
    while True:
        for _ in range(len(q)):
            (x, y, z) = q.popleft()
            for (dx, dy, dz) in moves:
                ax = x+dx
                ay = y+dy
                az = z+dz
                if not (0 <= ax < H and 0 <= ay < N and 0 <= az < M):
                    continue
                if visit[ax][ay][az] or a[ax][ay][az] != 0:
                    continue
                visit[ax][ay][az] = True
                a[ax][ay][az] = 1
                q.append((ax, ay, az))
        if len(q) == 0:
            break
        days += 1

    for i in range(H):
        for j in range(N):
            for k in range(M):
                if a[i][j][k] == 0:
                    return -1

    return days


M, N, H = map(int, read().split())
a = []
for i in range(H):
    a.append([])
    for _ in range(N):
        a[i].append(list(map(int, read().split())))

days = process()
print(days)
