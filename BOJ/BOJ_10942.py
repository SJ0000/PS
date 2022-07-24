

import sys


def read():
    return sys.stdin.readline().rstrip()


def calculatePalendrome():
    global a, d, N
    # 길이가 1일때
    for i in range(N):
        d[i][i] = True
    # 길이가 2일때
    for i in range(N-1):
        d[i][i+1] = (a[i] == a[i+1])

    for length in range(3, N+1):
        for start in range(N-length+1):
            end = start+length-1
            d[start][end] = d[start+1][end-1] and a[start] == a[end]


N = int(read())
a = list(map(int, read().split()))
d = [[False for _ in range(N)] for __ in range(N)]

calculatePalendrome()

M = int(read())
for _ in range(M):
    S, E = map(int, read().split())
    result = 1 if d[S-1][E-1] else 0
    print(result)
