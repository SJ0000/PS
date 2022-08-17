
from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def down(board, col, block):
    if block == 1 or block == 3:
        row = -1
        for i in range(6):
            if board[i][col] == 1:
                row = i-1
                break
        if block == 1:
            board[row][col] = 1
        if block == 3:
            board[row][col] = board[row-1][col] = 1
    if block == 2:
        row = -1
        for i in range(6):
            if board[i][col] + board[i][col+1] > 0:
                row = i-1
                break
        board[row][col] = board[row][col+1] = 1


def clear(board, row):
    for i in range(row-1, -1, -1):
        board[i+1] = board[i][:]
    board[0] = [0, 0, 0, 0]


def remove_full(board):
    global point
    removed = []
    for i in range(6):
        if sum(board[i]) == 4:
            removed.append(i)
    for row in removed:
        clear(board, row)
        point += 1


def remove_special_row(board):
    for _ in range(2):
        if sum(board[1]) > 0:
            clear(board, 5)


def process(board, col, block):
    down(board, col, block)
    remove_full(board)
    remove_special_row(board)


def count(board):
    result = 0
    for row in board:
        result += sum(row)
    return result


green = [[0, 0, 0, 0] for _ in range(6)]
blue = [[0, 0, 0, 0] for _ in range(6)]

N = int(read())
point = 0

for _ in range(N):
    t, x, y = map(int, read().split())
    process(green, y, t)
    if t == 1:
        process(blue, 3-x, 1)
    elif t == 2:
        process(blue, 3-x, 3)
    else:
        process(blue, 2-x, 2)

print(point)
print(count(green)+count(blue))
