

# 로직은 맞는데 시간초과 발생
# Queue에서 꺼내면서 costs를 업데이트 하는 방식에서
# Queue에 넣기 전에 costs를 업데이트 하는 방식으로 변경
# (Queue에 들어가는 갯수를 줄인다.)

from collections import deque


def solution(board):

    n = len(board)
    q = deque()
    costs = [[[987654321 for _ in range(2)]
              for __ in range(n)] for ___ in range(n)]
    vertical_moves = [(1, 0), (-1, 0)]
    horizontal_moves = [(0, 1), (0, -1)]

    def can_visit(x, y, is_vertical, cost):
        if not (0 <= x < n and 0 <= y < n):
            return False
        if board[x][y] == 1:
            return False
        if costs[x][y][is_vertical] < cost:
            return False
        return True

    q.append((0, 0, 0, 0))
    q.append((0, 0, 1, 0))
    costs[0][0][0] = 0
    costs[0][0][0] = 1

    while len(q) > 0:
        (x, y, is_vertical, cost) = q.popleft()
        # 자신보다 x,y에 적은 cost로 도착한게 있을 경우
        if costs[x][y][is_vertical] < cost:
            continue

        if x == n-1 and y == n-1:
            continue

        for (vx, vy) in vertical_moves:
            nx = x+vx
            ny = y+vy
            ncost = cost + 100 if is_vertical != 1 else cost + 600
            if can_visit(nx, ny, 0, ncost):
                costs[nx][ny][0] = ncost
                q.append((nx, ny, 0, ncost))

        for (hx, hy) in horizontal_moves:
            nx = x+hx
            ny = y+hy
            ncost = cost + 100 if is_vertical != 0 else cost + 600
            if can_visit(nx, ny, 1, ncost):
                costs[nx][ny][1] = ncost
                q.append((nx, ny, 1, ncost))

    return min(costs[n-1][n-1])


print(solution(
    [[0, 0, 0, 0, 0, 0],
     [0, 1, 1, 1, 1, 0],
     [0, 0, 1, 0, 0, 0],
     [1, 0, 0, 1, 0, 1],
     [0, 1, 0, 0, 0, 1],
     [0, 0, 0, 0, 0, 0]]))
