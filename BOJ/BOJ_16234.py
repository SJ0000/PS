from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def get_component(x, y):
    global N, L, R, a, visit
    moves = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    q = deque()
    q.append((x, y))
    visit[x][y] = True
    component = []
    while len(q) > 0:
        (ax, ay) = q.popleft()
        component.append((ax, ay))
        for (dx, dy) in moves:
            nx = ax+dx
            ny = ay+dy
            if not (0 <= nx < N and 0 <= ny < N):
                continue
            if visit[nx][ny]:
                continue
            if L <= abs(a[ax][ay] - a[nx][ny]) <= R:
                visit[nx][ny] = True
                q.append((nx, ny))
    return component


def move_process(component):
    global a
    total = 0
    for (x, y) in component:
        total += a[x][y]
    for (x, y) in component:
        a[x][y] = total // len(component)


a = []
N, L, R = map(int, read().split())
for _ in range(N):
    a.append(list(map(int, read().split())))

days = 0
while True:
    visit = [[False for _ in range(N)] for __ in range(N)]
    components = []
    for i in range(N):
        for j in range(N):
            if not visit[i][j]:
                components.append(get_component(i, j))
    # 인구이동이 없는 경우
    if len(components) == N*N:
        break
    for component in components:
        move_process(component)
    days += 1

print(days)
