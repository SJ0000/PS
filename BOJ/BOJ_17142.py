

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def simulation(selected):
    global N, M, origin, empty, virus
    a = []
    q = deque()
    visit = [[False for _ in range(N)] for __ in range(N)]
    dirs = [(0, 1), (1, 0), (-1, 0), (0, -1)]
    empty_set = set(empty)
    for row in origin:
        a.append(row[:])

    for i in range(len(virus)):
        if selected & (1 << i) != 0:
            (x, y) = virus[i]
            q.append(virus[i])
            visit[x][y] = True

    time = 0
    is_possible = False

    while len(q) > 0:
        qs = len(q)

        for _ in range(qs):
            (x, y) = q.popleft()
            empty_set.discard((x, y))
            for (dx, dy) in dirs:
                ax, ay = x+dx, y+dy
                if not (0 <= ax < N and 0 <= ay < N):
                    continue
                if visit[ax][ay] or a[ax][ay] == 1:
                    continue
                q.append((ax, ay))
                visit[ax][ay] = True

        if len(empty_set) == 0:
            is_possible = True
            break

        time += 1

    return time if is_possible else -1


N, M = map(int, read().split())
origin = []
for _ in range(N):
    origin.append(list(map(int, read().split())))

virus = []
empty = []
for i in range(N):
    for j in range(N):
        if origin[i][j] == 2:
            virus.append((i, j))
        if origin[i][j] == 0:
            empty.append((i, j))

answer = 987654321
for i in range(1 << len(virus)):
    count = 0
    for x in range(len(virus)):
        if i & (1 << x) != 0:
            count += 1
    if count == M:
        result = simulation(i)
        if result != -1:
            answer = min(answer, result)

if answer == 987654321:
    print(-1)
else:
    print(answer)
