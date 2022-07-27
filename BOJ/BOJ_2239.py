

import sys


def read():
    return sys.stdin.readline().rstrip()


def is_possible(x, y, number):
    global a

    # 행, 열
    for i in range(9):
        if a[x][i] == number:
            return False
        if a[i][y] == number:
            return False
    # 3x3
    r = (x//3)*3
    c = (y//3)*3
    for i in range(3):
        for j in range(3):
            if a[r+i][c+j] == number:
                return False

    return True


def get_next(position):
    global a
    (x, y) = position
    for i in range(y+1, 9):
        if a[x][i] == 0:
            return (x, i)
    for i in range(x+1, 9):
        for j in range(9):
            if a[i][j] == 0:
                return (i, j)
    return None


def dfs(position):
    global a
    if position == None:
        return True
    (x, y) = position
    next = get_next(position)
    for num in range(1, 9+1):
        if is_possible(x, y, num):
            a[x][y] = num
            result = dfs(next)
            if result:
                return True
            a[x][y] = 0

    if a[x][y] == 0:
        return False


a = []
for _ in range(9):
    a.append(list(map(int, list(read()))))

start_position = get_next((0, -1))
dfs(start_position)

for row in a:
    print(''.join(list(map(str, row))))
