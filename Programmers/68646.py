

def solution(a):
    n = len(a)
    if n <= 2:
        return n
    # 길이 3 이상일 때
    max_value = 1000000000
    # 0 ~ i번째 까지 최소값
    f_min = [max_value for _ in range(n)]
    # i번 ~ n-1번째 까지 최소값
    b_min = [max_value for _ in range(n)]

    f_min[0] = a[0]
    for i in range(1, n):
        f_min[i] = min(f_min[i-1], a[i])
    b_min[n-1] = a[n-1]
    for i in range(n-2, -1, -1):
        b_min[i] = min(b_min[i+1], a[i])

    answer = 2
    for i in range(1, n-1):
        if f_min[i-1] < a[i] and b_min[i+1] < a[i]:
            continue
        answer += 1

    return answer


print(solution([-16, 27, 65, -2, 58, -92, -71, -68, -61, -33]))
