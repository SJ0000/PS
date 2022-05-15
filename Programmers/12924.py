def solution(n):
    MAXN = 10000
    psum = [0 for _ in range(MAXN+1)]
    psum[0] = 0
    for i in range(1, MAXN+1):
        psum[i] = psum[i-1]+i

    answer = 0
    for st in range(0, n+1):
        for ed in range(st+1, n+1):
            current = psum[ed]-psum[st]
            if current > n:
                break

            if current == n:
                # print(st, ed)
                answer += 1
                break

    return answer


print(solution(10000))
