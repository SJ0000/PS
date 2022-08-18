
from collections import deque

import sys


def read():
    return sys.stdin.readline().rstrip()


a = [[None for _ in range(4)] for __ in range(4)]
fishes = [None for _ in range(16)]
max_point = 0
dirs = [(-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1)]

for i in range(4):
    info = list(map(int, read().split()))
    for j in range(0, 8, 2):
        num, dir = info[j], info[j+1]-1
        a[i][j//2] = num
        fishes[num-1] = [i, j//2, dir, True]


def move_fishes(a, fishes):
    for i in range(16):
        (x, y, dir, alive) = fishes[i]
        if not alive:
            continue
        for ndir in range(dir, dir+8):
            if ndir >= 8:
                ndir -= 8
            (dx, dy) = dirs[ndir]
            nx, ny = x+dx, y+dy
            if not (0 <= nx < 4 and 0 <= ny < 4):
                continue
            if a[nx][ny] == 99:
                continue
            # 이동
            if a[nx][ny] == 0:
                a[x][y] = 0
                a[nx][ny] = i+1
                fishes[i] = [nx, ny, ndir, alive]
            else:
                # swap i,j
                j = a[nx][ny]-1
                fishes[i] = [nx, ny, ndir, alive]
                fishes[j][0] = x
                fishes[j][1] = y
                a[nx][ny] = i+1
                a[x][y] = j+1
            break


def copy(a, fishes):
    copy_a = []
    for row in a:
        copy_a.append(row[:])
    copy_fishes = []
    for row in fishes:
        copy_fishes.append(row[:])
    return (copy_a, copy_fishes)


def dfs(x, y, a, fishes, point):
    global max_point
    if a[x][y] == 0:
        max_point = max(max_point, point)
        return

    fish_index = a[x][y]-1
    point += a[x][y]
    fishes[fish_index][3] = False
    a[x][y] = 99
    shark_dir = fishes[fish_index][2]

    move_fishes(a, fishes)
    a[x][y] = 0

    (dx, dy) = dirs[shark_dir]
    while True:
        x += dx
        y += dy
        if not (0 <= x < 4 and 0 <= y < 4):
            break
        (copy_a, copy_fishes) = copy(a, fishes)
        dfs(x, y, copy_a, copy_fishes, point)

    max_point = max(max_point, point)


dfs(0, 0, a, fishes, 0)
print(max_point)
