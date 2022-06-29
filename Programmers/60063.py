
from collections import deque


def solution(board):
    n = len(board)
    # 가로 0, 세로 1
    visit = [[[False, False] for _ in range(n)] for __ in range(n)]
    dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def is_zero_and_in_range(pos):
        (x, y) = pos
        if not (0 <= x < n and 0 <= y < n):
            return False
        return board[x][y] == 0

    def can_rotate(pos, clockwise):
        (x, y, mode) = pos
        if mode == 0:
            xdiff = 1 if clockwise else -1
            positions = [(x+xdiff, y), (x+xdiff, y+1)]
            for position in positions:
                if not is_zero_and_in_range(position):
                    return False
        else:
            ydiff = -1 if clockwise else 1
            positions = [(x, y+ydiff), (x+1, y+ydiff)]
            for position in positions:
                if not is_zero_and_in_range(position):
                    return False

        return True

    def rotate(pos, clockwise):
        # 한 점을 축으로 시계방향 회전이 가능하면
        # 다른 힌 점을 축으로 반시계 방향 회전이 가능하다

        (x, y, mode) = pos
        if mode == 0:
            xdiff = 0 if clockwise else -1
            return [(x+xdiff, y, 1), (x+xdiff, y+1, 1)]
        else:
            ydiff = -1 if clockwise else 0
            return [(x, y+ydiff, 0), (x+1, y+ydiff, 0)]

    def can_move(pos, dir):
        (x, y, mode) = pos
        (dx, dy) = dir
        ax = x+dx
        ay = y+dy
        next = [(ax, ay)]
        if mode == 0:
            next.append((ax, ay+1))
        else:
            next.append((ax+1, ay))

        for position in next:
            if not is_zero_and_in_range(position):
                return False
        return True

    def move(pos, dir):
        (x, y, mode) = pos
        (dx, dy) = dir
        return (x+dx, y+dy, mode)

    # bfs
    q = deque()
    q.append((0, 0, 0))
    visit[0][0][0] = True

    count = 0
    while len(q) > 0:
        for i in range(len(q)):
            current = q.popleft()
            (x, y, mode) = current

            # 도착
            if mode == 0 and x == n-1 and y == n-2:
                return count
            if mode == 1 and x == n-2 and y == n-1:
                return count

            # 회전
            for clockwise in [True, False]:
                if can_rotate(current, clockwise):
                    rotated = rotate(current, clockwise)
                    for (rx, ry, rmode) in rotated:
                        if visit[rx][ry][rmode]:
                            continue
                        visit[rx][ry][rmode] = True
                        q.append((rx, ry, rmode))
            for dir in dirs:
                if can_move(current, dir):
                    (mx, my, mmode) = move(current, dir)
                    if visit[mx][my][mmode]:
                        continue
                    visit[mx][my][mmode] = True
                    q.append((mx, my, mmode))

        count += 1

    return -1


print(solution([[0, 0, 0, 1, 1], [0, 0, 0, 1, 0], [
      0, 1, 0, 1, 1], [1, 1, 0, 0, 1], [0, 0, 0, 0, 0]]))
