

def solution(n):

    # n에서부터 출발해서 0으로 도착
    answer = 0

    while n != 0:
        if n % 2 == 0:
            n /= 2
        else:
            n -= 1
            answer += 1

    return answer


print(solution(6))
