
# d[i][j] = i번째화폐까지 사용해서 j원을 만드는 방법의 갯수

# d[i][j]
#   - d[i-1][j] (i번을 제외하고 만드는 경우)
#   - d[i][j-money[i]] : i번째 화폐를 포함하면서 j-money[i]원을 만들 수 있는 방법

def solution(n, money):
    MOD = 1000000007

    d = [[0 for _ in range(n+1)] for __ in range(len(money))]
    money.sort()

    # 첫 번째 화폐만을 이용하는 경우
    for j in range(1, n+1):
        if j % money[0] == 0:
            d[0][j] = 1

    for i in range(1, len(money)):
        m = money[i]
        d[i][m] += 1
        for j in range(1, n+1):
            d[i][j] += d[i-1][j]
            if j-m >= 0:
                d[i][j] += d[i][j-m]
            d[i][j] %= MOD

    return d[len(money)-1][n]


print(solution(5, [1, 2, 5]))
