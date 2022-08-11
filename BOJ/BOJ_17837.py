

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def solution(N, K, a, pieces):
    WHITE, RED, BLUE = 0, 1, 2
    dirs = [(0, 1), (0, -1), (-1, 0), (1, 0)]

    def delete(src, targets):
        for target in targets:
            if target in src:
                src.remove(target)

    def move(x, y, uppers):
        for upper in uppers:
            pieces[upper][0] = x
            pieces[upper][1] = y

    def pile(piece, items):
        pieces[piece][3] += items

    def reverse(uppers):
        n = len(uppers)

        for item in uppers:
            pieces[item][3] = []

        for i in range(n):
            for j in range(i, n):
                pieces[uppers[j]][3].insert(0, uppers[i])

    for turn in range(1, 1001):
        for i in range(K):
            [x, y, dir, uppers] = pieces[i]
            (dx, dy) = dirs[dir]
            nx, ny = x+dx, y+dy

            if not (0 <= nx < N and 0 <= ny < N) or a[nx][ny] == BLUE:
                dir = dir+1 if dir % 2 == 0 else dir - 1
                pieces[i][2] = dir
                (dx, dy) = dirs[dir]
                nx, ny = x+dx, y+dy

            if not (0 <= nx < N and 0 <= ny < N) or a[nx][ny] == BLUE:
                continue

            if a[nx][ny] == WHITE:
                # 나를 업고 있던 것들에서 나를 제거
                for j in range(K):
                    if i == j:
                        continue
                    if i in pieces[j][3]:
                        delete(pieces[j][3], uppers)

                # 이동한 위치에 말이 존재할 경우 올리기
                for j in range(K):
                    if i == j:
                        continue
                    if pieces[j][0] == nx and pieces[j][1] == ny:
                        pile(j, uppers)

                # 업고 이동
                move(nx, ny, uppers)

            if a[nx][ny] == RED:
                # 나를 업고 있던 것들에서 나를 제거
                for j in range(K):
                    if i == j:
                        continue
                    if i in pieces[j][3]:
                        delete(pieces[j][3], uppers)

                # 이동할 곳에 말이 있으면 나를 뒤집어서 올리기
                for j in range(K):
                    if i == j:
                        continue
                    if pieces[j][0] == nx and pieces[j][1] == ny:
                        pile(j, uppers[::-1])

                # 이동한 묶음 뒤집기
                reverse(uppers)

                # 업고 이동
                move(nx, ny, uppers)

            for j in range(K):
                if len(pieces[j][3]) >= 4:
                    return turn

    return -1


N, K = map(int, read().split())
a = []
pieces = []
for _ in range(N):
    a.append(list(map(int, read().split())))

for i in range(K):
    (x, y, dir) = map(lambda x: int(x)-1, read().split())
    pieces.append([x, y, dir, [i]])

print(solution(N, K, a, pieces))
