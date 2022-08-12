

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def rotate(i, k):
    # 시계방향 회전
    global board
    for _ in range(k):
        last = board[i].pop()
        board[i].appendleft(last)


def find_targets():
    global N, M, board
    # 인접하면서 같은 수를 찾는다.
    # 하나라도 있으면 true, 없으면 false
    targets = set()
    # 좌우 인접
    for i in range(1, N+1):
        if board[i][0] != 0 and board[i][0] == board[i][M-1]:
            targets.add((i, 0))
            targets.add((i, M-1))
        for j in range(0, M-1):
            if board[i][j] == 0:
                continue
            if board[i][j] == board[i][j+1]:
                targets.add((i, j))
                targets.add((i, j+1))

    # 상하 인접
    for i in range(1, N):
        for j in range(M):
            if board[i][j] == 0:
                continue
            if board[i][j] == board[i+1][j]:
                targets.add((i, j))
                targets.add((i+1, j))

    return targets


def average_process():
    global N, M, board
    count = 0
    sum = 0
    for i in range(1, N+1):
        for value in board[i]:
            if value == 0:
                continue
            count += 1
            sum += value
    if count == 0:
        return
    average = sum/count
    for i in range(1, N+1):
        for j in range(M):
            if board[i][j] == 0:
                continue
            if board[i][j] > average:
                board[i][j] -= 1
                continue
            if board[i][j] < average:
                board[i][j] += 1


N, M, T = map(int, read().split())
board = [deque()]

for _ in range(N):
    board.append(deque(list(map(int, read().split()))))

for _ in range(T):
    x, d, k = map(int, read().split())
    if d == 1:
        k = M-k
    for i in range(1, N+1):
        if i % x != 0:
            continue
        rotate(i, k)
    targets = find_targets()
    if len(targets) == 0:
        average_process()
    else:
        for (i, j) in targets:
            board[i][j] = 0

answer = 0
for row in board:
    answer += sum(row)
print(answer)
