

from collections import deque
import sys


MOD = 1000000007


def read():
    return sys.stdin.readline().rstrip()


def multiple(mat1, mat2):
    n = len(mat1)
    m = len(mat2)
    p = len(mat2[0])
    result = [[0 for _ in range(p)] for __ in range(n)]

    for i in range(n):
        a = mat1[i]
        for j in range(p):
            b = [row[j] for row in mat2]
            total = 0
            for (ai, bi) in zip(a, b):
                total += ((ai % MOD)*(bi % MOD))
                total %= MOD
            result[i][j] = total
    return result


def solution(n):
    global mats
    if n == 1:
        return 0

    st = [[1, 0, 0, 0, 0, 0, 0, 0]]
    for i in range(1, 31):
        if n & (1 << (i-1)) == 0:
            continue
        st = multiple(st, mats[i])

    return st[0][0]


mat = [
    [0, 1, 1, 0, 0, 0, 0, 0],
    [1, 0, 1, 1, 0, 0, 0, 0],
    [1, 1, 0, 1, 1, 0, 0, 0],
    [0, 1, 1, 0, 1, 1, 0, 0],
    [0, 0, 1, 1, 0, 1, 0, 1],
    [0, 0, 0, 1, 1, 0, 1, 0],
    [0, 0, 0, 0, 0, 1, 0, 1],
    [0, 0, 0, 0, 1, 0, 1, 0]
]
# 2^i
mats = []
mats.append([[]])
mats.append(mat)
for i in range(2, 31):
    square = multiple(mats[i-1], mats[i-1])
    mats.append(square)

n = int(read())
print(solution(n))
