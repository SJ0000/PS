

def solution(n):
    mod = 1234567

    d = [0 for _ in range(n+1)]
    d[0] = 1
    d[1] = 1
    for i in range(2, n+1):
        d[i] = d[i-1] + d[i-2]
        d[i] %= mod

    return d[n]


print(solution(4))
