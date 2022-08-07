

import sys


def read():
    return sys.stdin.readline().rstrip()


def fishing(column):
    global a, R
    shark = 0
    for i in range(R):
        z = a[i][column][2]
        if z == -1:
            continue
        shark = z
        a[i][column] = (-1, -1, -1)
        break
    return shark


def change_dir(dir):
    if dir % 2 == 0:
        return dir+1
    return dir - 1

# 0 1 2 3 위 아래 오른쪽 왼쪽


def next_position(r, c, s, d):
    global R, C, dirs
    if s == 0:
        return (r, c, s, d)

    (dx, dy) = dirs[d]
    for _ in range(s):
        if (r == 0 and d == 0) or (r == R-1 and d == 1) or (c == 0 and d == 3) or (c == C-1 and d == 2):
            d = change_dir(d)
            (dx, dy) = dirs[d]
        r += dx
        c += dy
    return (r, c, s, d)


def move_shark():
    global a, R, C
    sharks = []
    for i in range(R):
        for j in range(C):
            (s, d, z) = a[i][j]
            if z == -1:
                continue
            a[i][j] = (-1, -1, -1)
            (next_r, next_c, s, next_d) = next_position(i, j, s, d)
            sharks.append((next_r, next_c, s, next_d, z))

    for (r, c, s, d, z) in sharks:
        exist_shark_size = a[r][c][2]
        if exist_shark_size > z:
            continue
        a[r][c] = (s, d, z)


# 0 1 2 3 위 아래 오른쪽 왼쪽
dirs = [(-1, 0), (1, 0), (0, 1), (0, -1)]

R, C, M = map(int, read().split())
a = [[(-1, -1, -1) for _ in range(C)] for __ in range(R)]

for _ in range(M):
    r, c, s, d, z = map(int, read().split())
    r -= 1
    c -= 1
    d -= 1
    if d == 0 or d == 1:
        s %= ((R-1)*2)
    if d == 2 or d == 3:
        s %= ((C-1)*2)
    a[r][c] = (s, d, z)


answer = 0
for i in range(C):
    answer += fishing(i)
    move_shark()
print(answer)
