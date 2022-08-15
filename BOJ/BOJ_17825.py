
from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def get_next(current, move):
    global next

    if current == 5:
        current = 21
        move -= 1
    elif current == 10:
        current = 24
        move -= 1
    elif current == 15:
        current = 26
        move -= 1

    for _ in range(move):
        current = next[current]
    return current


def dfs(turn, selected, point, positions):
    global answer, dice, points
    if turn == 10:
        answer = max(answer, point)
        return

    next_position = get_next(positions[selected], dice[turn])

    # 이동 불가능
    for i in range(4):
        if i == selected:
            continue
        if positions[i] != 32 and positions[i] == next_position:
            return

    # 포인트 획득 후 이동
    next_positions = positions[:]
    next_positions[selected] = next_position
    next_point = point + points[next_position]
    for i in range(4):
        dfs(turn+1, i, next_point, next_positions)


points = [0, 2, 4, 6, 8, 10, 12, 14, 16, 18,
          20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 13, 16, 19, 22, 24, 28, 27, 26, 25, 30, 35, 0]


next = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
        18, 19, 20, 32, 22, 23, 29, 25, 29, 27, 28, 29, 30, 31, 20, 32]


dice = list(map(int, read().split()))

answer = -1

for i in range(4):
    dfs(0, i, 0, [0, 0, 0, 0])

print(answer)
