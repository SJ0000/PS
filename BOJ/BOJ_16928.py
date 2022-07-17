
from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def solution(board):
    visit = [False for _ in range(101)]
    moves = [1, 2, 3, 4, 5, 6]
    q = deque()
    q.append(1)
    visit[1] = True
    result = 0
    while len(q) > 0:
        for _ in range(len(q)):
            current = q.popleft()
            if current == 100:
                return result
            for move in moves:
                if not (0 <= current + move <= 100):
                    continue
                next = board[current+move]
                if visit[next]:
                    continue
                visit[next] = True
                q.append(next)
        result += 1
    return -1


N, M = map(int, read().split())
board = [i for i in range(101)]

for _ in range(N+M):
    x, y = map(int, read().split())
    board[x] = y

result = solution(board)
print(result)
