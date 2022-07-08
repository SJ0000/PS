
from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def shark_position():
    global a, N
    for i in range(N):
        for j in range(N):
            if a[i][j] == 9:
                return (i, j)


def next_target():
    # 길이, 좌표 를 반환
    global shark, a, N
    targets = []
    size, _, (x, y) = shark
    for i in range(N):
        for j in range(N):
            if i == x and j == y:
                continue
            if 1 <= a[i][j] <= 6 and a[i][j] < size:
                targets.append((i, j))
    if len(targets) == 0:
        return None
    targets = sorted(list(map(lambda pos: (get_distance(pos), pos), targets)))
    targets = list(filter(lambda info: info[0] != -1, targets))
    if len(targets) == 0:
        return None
    min_dist = targets[0][0]
    targets = sorted(list(filter(lambda info: info[0] == min_dist, targets)))
    return targets[0]


def get_distance(dest):
    global shark, a, N
    visit = [[False for _ in range(N)] for __ in range(N)]
    moves = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    size, _, (x, y) = shark
    q = deque()
    q.append((x, y))
    visit[x][y] = True
    move_count = 0
    while len(q) > 0:
        for __ in range(len(q)):
            (ax, ay) = q.popleft()
            if (ax, ay) == dest:
                return move_count

            for (dx, dy) in moves:
                nx = ax+dx
                ny = ay+dy
                if not (0 <= nx < N and 0 <= ny < N):
                    continue
                if visit[nx][ny]:
                    continue
                if not (a[nx][ny] == 0 or (nx, ny) == dest or a[nx][ny] == size):
                    continue
                visit[nx][ny] = True
                q.append((nx, ny))

        move_count += 1
    return -1


a = []
N = int(read())
for _ in range(N):
    a.append(list(map(int, read().split())))

# 크기, 먹은 갯수, 위치
shark = (2, 0, shark_position())

time = 0
while True:
    next = next_target()
    if next == None:
        break
    # 먹음
    move_count, (nx, ny) = next
    size, eat, (shark_x, shark_y) = shark
    a[shark_x][shark_y] = 0
    time += move_count
    if size == eat+1:
        shark = (size+1, 0, (nx, ny))
    else:
        shark = (size, eat+1, (nx, ny))
    a[nx][ny] = 9

print(time)
