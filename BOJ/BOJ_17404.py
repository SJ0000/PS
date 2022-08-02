
import sys


def read():
    return sys.stdin.readline().rstrip()


def process(start_color, N, cost):
    d = [[0, 0, 0] for _ in range(N)]
    INF = 987654321
    prev_colors = [[1, 2], [0, 2], [0, 1]]

    for i in range(3):
        if i == start_color:
            d[0][i] = cost[0][i]
        else:
            d[0][i] = INF

    for i in range(1, N):
        for color in range(3):
            if i == N-1 and color == start_color:
                d[i][color] = INF
                continue
            prev_min = INF
            for prev_color in prev_colors[color]:
                prev_min = min(prev_min, d[i-1][prev_color])
            d[i][color] = prev_min + cost[i][color]

    return min(d[N-1])


N = int(read())
cost = []
for _ in range(N):
    cost.append(list(map(int, read().split())))

result = 987654231
for start_color in range(3):
    result = min(result, process(start_color, N, cost))
print(result)
