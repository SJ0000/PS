

import sys


def read():
    return sys.stdin.readline().rstrip()


def solution(wine):
    n = len(wine)
    d = [[0, 0] for _ in range(n)]
    if n <= 2:
        return sum(wine)
    d[0][1] = wine[0]
    d[1][1] = wine[0] + wine[1]
    d[1][0] = wine[0]
    for i in range(2, n):
        # i번째 와인을 먹지 않는 경우
        d[i][0] = max(d[i-1])
        d[i][1] = max(d[i-1][0], d[i-2][0]+wine[i-1])+wine[i]

    return max(d[n-1])


n = int(read())
wine = []
for _ in range(n):
    wine.append(int(read()))

print(solution(wine))
