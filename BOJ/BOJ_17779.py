

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def simulation(x, y, d1, d2):
    global N, A
    area = [[] for _ in range(5)]
    is_area5 = [[0 for _ in range(N+1)] for __ in range(N+1)]

    def set_area5_line():
        targets = []
        for d in range(d1+1):
            is_area5[x+d][y-d] = 1
            is_area5[x+d2+d][y+d2-d] = 1
            targets.append((x+d+1, y-d))
        targets.pop()

        for d in range(d2+1):
            is_area5[x+d][y+d] = 1
            is_area5[x+d1+d][y-d1+d] = 1
            targets.append((x+d+1, y+d))
        targets.pop()

        return targets

    def set_area5_inner(targets):
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        def dfs(x, y):
            is_area5[x][y] = 1
            for (dx, dy) in dirs:
                ax, ay = x+dx, y+dy
                if is_area5[ax][ay] == 0:
                    dfs(ax, ay)

        for (x, y) in targets:
            dfs(x, y)

    def find_area(r, c):
        if is_area5[r][c] == 1:
            return 4

        if 1 <= r < x+d1 and 1 <= c <= y:
            return 0
        if 1 <= r <= x+d2 and y < c <= N:
            return 1
        if x+d1 <= r <= N and 1 <= c < y-d1+d2:
            return 2
        if x+d2 < r <= N and y-d1+d2 <= c <= N:
            return 3
        return 4

    targets = set_area5_line()
    set_area5_inner(targets)

    for i in range(1, N+1):
        for j in range(1, N+1):
            area[find_area(i, j)].append(A[i][j])

    total = list(map(sum, area))
    return max(total) - min(total)


N = int(read())
A = []
A.append([0]*(N+1))
for _ in range(N):
    A.append([0] + list(map(int, read().split())))

answer = 987654321
for d1 in range(1, N+1):
    for d2 in range(1, N+1):
        for x in range(1, N+1):
            for y in range(1, N+1):
                if 1 <= x < x+d1+d2 <= N and 1 <= y-d1 < y < y+d2 <= N:
                    answer = min(answer, simulation(x, y, d1, d2))

print(answer)
