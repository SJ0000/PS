

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def bfs(x, y, id):
    global a, N, M, visit, size_dict, dirs
    count = 0
    q = deque()
    q.append((x, y))
    visit[x][y] = True
    while len(q) > 0:
        (ax, ay) = q.popleft()
        a[ax][ay] = id
        count += 1
        for (dx, dy) in dirs:
            nx, ny = ax+dx, ay+dy
            if 0 <= nx < N and 0 <= ny < M and not visit[nx][ny] and a[nx][ny] == 0:
                q.append((nx, ny))
                visit[nx][ny] = True
    size_dict[id] = count


dirs = [(0, 1), (1, 0), (-1, 0), (0, -1)]
N, M = map(int, read().split())

# -1 벽, 0 미방문, 1 ~ 탐색 완료
a = []
for _ in range(N):
    a.append(list(map(lambda x: 0 if x == '0' else -1, list(read()))))

visit = [[False for _ in range(M)] for __ in range(N)]
id = 1

size_dict = dict()

for i in range(N):
    for j in range(M):
        if a[i][j] == 0 and not visit[i][j]:
            bfs(i, j, id)
            id += 1

walls = []
for i in range(N):
    for j in range(M):
        if a[i][j] != -1:
            continue
        s = set()
        for (dx, dy) in dirs:
            nx, ny = i+dx, j+dy
            if 0 <= nx < N and 0 <= ny < M and a[nx][ny] > 0:
                s.add(a[nx][ny])
        reachables = 1
        for id in s:
            reachables += size_dict[id]
        walls.append((i, j, str(reachables % 10)))

answer = [['0' for _ in range(M)] for __ in range(N)]
for (x, y, value) in walls:
    answer[x][y] = value

for row in answer:
    print(''.join(row))
