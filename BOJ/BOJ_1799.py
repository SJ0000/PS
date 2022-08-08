

import sys


def read():
    return sys.stdin.readline().rstrip()


def possible(x, y):
    global a, n, check
    if a[x][y] == 0:
        return False

    for (dx, dy) in check:
        ax, ay = x, y
        while 0 <= ax < n and 0 <= ay < n:
            if a[ax][ay] == 2:
                return False
            ax += dx
            ay += dy

    return True


def go(x, y, count, is_black):
    global a, n, black, white

    if is_black:
        black = max(black, count)
    else:
        white = max(white, count)

    a[x][y] = 2

    # x행
    for j in range(y+2, n, 2):
        if possible(x, j):
            go(x, j, count+1, is_black)
    # 나머지 행
    st = -1
    for i in range(x+1, n):
        if is_black:
            st = 0 if i % 2 == 0 else 1
        else:
            st = 1 if i % 2 == 0 else 0

        for j in range(st, n, 2):
            if possible(i, j):
                go(i, j, count+1, is_black)
    a[x][y] = 1


def solution():
    global a, n, black, white
    # black
    for i in range(n):
        st = 0 if i % 2 == 0 else 1
        for j in range(st, n, 2):
            if a[i][j] == 0:
                continue
            go(i, j, 1, True)

    # white
    for i in range(n):
        st = 1 if i % 2 == 0 else 0
        for j in range(st, n, 2):
            if a[i][j] == 0:
                continue
            go(i, j, 1, False)


n = int(read())
a = []
check = [(-1, -1),  (-1, 1)]
for _ in range(n):
    a.append(list(map(int, read().split())))

black, white = 0, 0
solution()
print(black+white)
