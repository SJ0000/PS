

def solution(m, n, puddles):

    MOD = 1000000007
    d = [[0 for _ in range(m)] for _ in range(n)]
    puddles = set(map(lambda x: (x[1]-1, x[0]-1), puddles))

    d[0][0] = 1
    for i in range(n):
        for j in range(m):
            if (i, j) in puddles:
                continue

            if i >= 1:
                d[i][j] += d[i-1][j] % MOD
            if j >= 1:
                d[i][j] += d[i][j-1] % MOD
            d[i][j] %= MOD

    return d[n-1][m-1]


print(solution(5, 5, [[2, 2], [4, 3]]))
