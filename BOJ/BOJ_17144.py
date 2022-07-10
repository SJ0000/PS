

import sys


def read():
    return sys.stdin.readline().rstrip()


def spread():
    global a, R, C
    moves = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    dusts = []
    for i in range(R):
        for j in range(C):
            if a[i][j] > 0:
                dusts.append([(i, j), a[i][j]])
                a[i][j] = 0

    for [(x, y), dust] in dusts:
        remain = dust
        for (dx, dy) in moves:
            ax = x+dx
            ay = y+dy
            if not (0 <= ax < R and 0 <= ay < C):
                continue
            if a[ax][ay] == -1:
                continue
            a[ax][ay] += dust//5
            remain -= dust//5
        a[x][y] += remain


def init_cleaner():
    global a, R, C, upper_rotate, lower_rotate
    upper = lower = (-1, -1)
    for i in range(R):
        find = False
        for j in range(C):
            if a[i][j] == -1:
                upper = (i, j)
                lower = (i+1, j)
                find = True
                break
        if find:
            break

    ux, uy = upper
    while uy < C-1:
        uy += 1
        upper_rotate.append((ux, uy))

    while ux > 0:
        ux -= 1
        upper_rotate.append((ux, uy))

    while uy > 0:
        uy -= 1
        upper_rotate.append((ux, uy))

    while ux < upper[0]:
        ux += 1
        upper_rotate.append((ux, uy))

    while uy < upper[1]-1:
        uy += 1
        upper_rotate.append((ux, uy))

    lx, ly = lower

    while ly < C-1:
        ly += 1
        lower_rotate.append((lx, ly))

    while lx < R-1:
        lx += 1
        lower_rotate.append((lx, ly))

    while ly > 0:
        ly -= 1
        lower_rotate.append((lx, ly))

    while lx > lower[0]:
        lx -= 1
        lower_rotate.append((lx, ly))

    while ly < lower[1]-1:
        ly += 1
        lower_rotate.append((lx, ly))

    return [upper_rotate, lower_rotate]


def clean(rotate):
    global a
    prev = 0
    for (x, y) in rotate:
        if a[x][y] == -1:
            return
        temp = a[x][y]
        a[x][y] = prev
        prev = temp


a = []
R, C, T = map(int, read().split())

for _ in range(R):
    a.append(list(map(int, read().split())))

upper_rotate = []
lower_rotate = []
init_cleaner()

for _ in range(T):
    spread()
    clean(upper_rotate)
    clean(lower_rotate)

result = 0
for i in range(R):
    for j in range(C):
        if a[i][j] >= 0:
            result += a[i][j]

print(result)
