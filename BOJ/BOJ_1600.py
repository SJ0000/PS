

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def solution():
    global K, W, H, a

    def can_visit(x, y, k):
        if not (0 <= x < H and 0 <= y < W):
            return False
        if a[x][y] == 1:
            return False
        return not visit[x][y][k]

    # visit[i][j][k] = i,j에 말 무빙 k개 남기고 도착
    visit = [[[False for _ in range(K+1)] for __ in range(W)]
             for ___ in range(H)]

    normal = [(0, 1), (1, 0), (-1, 0), (0, -1)]
    horse = [(1, 2), (-1, 2), (1, -2), (-1, -2),
             (2, 1), (-2, 1), (2, -1), (-2, -1)]

    q = deque()
    q.append((0, 0, K))
    visit[0][0][K] = True

    count = 0
    while len(q) > 0:
        qs = len(q)
        for _ in range(qs):
            (x, y, k) = q.popleft()
            if x == H-1 and y == W-1:
                return count
            if k > 0:
                for (dx, dy) in horse:
                    ax, ay = x+dx, y+dy
                    if can_visit(ax, ay, k-1):
                        visit[ax][ay][k-1] = True
                        q.append((ax, ay, k-1))
            for (dx, dy) in normal:
                ax, ay = x+dx, y+dy
                if can_visit(ax, ay, k):
                    visit[ax][ay][k] = True
                    q.append((ax, ay, k))
        count += 1

    return -1


K = int(read())
W, H = map(int, read().split())
a = []
for _ in range(H):
    a.append(list(map(int, read().split())))

print(solution())
