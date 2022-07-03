
from collections import deque


def solution(rectangle, characterX, characterY, itemX, itemY):
    N = 101
    # 도형 안쪽이라 방문 불가능한 경우
    inner = [[False for _ in range(N+1)] for __ in range(N+1)]
    # 해당 좌표에서 위로 이동 가능한지
    u = [[False for _ in range(N+1)] for __ in range(N+1)]
    # 해당 좌표에서 오른쪽으로 이동 가능한지
    r = [[False for _ in range(N+1)] for __ in range(N+1)]

    def add_edge(ax, ay, bx, by):
        for i in range(ax, bx):
            r[i][ay] = r[i][by] = True
        for i in range(ay, by):
            u[ax][i] = u[bx][i] = True

    def check_inner(ax, ay, bx, by):
        for i in range(ax+1, bx):
            for j in range(ay+1, by):
                inner[i][j] = True

    # 가로,세로 길이가 1인 사각형은 inner 처리가 까다로움
    # 모든 입력을 2배로 늘린다
    rectangle = list(
        map(lambda x: (x[0]*2, x[1]*2, x[2]*2, x[3]*2), rectangle))
    characterX *= 2
    characterY *= 2
    itemX *= 2
    itemY *= 2

    for (ax, ay, bx, by) in rectangle:
        add_edge(ax, ay, bx, by)
        check_inner(ax, ay, bx, by)

    q = deque()
    count = 0
    visit = [[False for _ in range(N+1)] for __ in range(N+1)]
    moves = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    q.append((characterX, characterY))
    visit[characterX][characterY] = True

    def can_move(x, y, dx, dy):
        # 이미 방문한 경우
        if visit[x+dx][y+dy] == True:
            return False
        # 정사각형 내부인 경우
        if inner[x+dx][y+dy] == True:
            return False

        # 길이 있는지 확인
        if dx == 1:
            return r[x][y]
        if dx == -1:
            return r[x-1][y]
        if dy == 1:
            return u[x][y]
        if dy == -1:
            return u[x][y-1]

    while len(q) > 0:
        for _ in range(len(q)):
            (x, y) = q.popleft()
            if (x, y) == (itemX, itemY):
                return count//2

            for (dx, dy) in moves:
                if can_move(x, y, dx, dy):
                    ax = x+dx
                    ay = y+dy
                    visit[ax][ay] = True
                    q.append((ax, ay))

        count += 1

    return 0


print(solution([[1, 1, 7, 4], [3, 2, 5, 5], [
      4, 3, 6, 9], [2, 6, 8, 8]], 1, 3, 7, 8))
