
def process(times, minutes):
    x = list(map(lambda time: minutes//time, times))
    return sum(x)


def solution(n, times):
    times = sorted(times)
    left = 0
    right = times[-1]*n
    answer = 0
    while left <= right:
        mid = (left+right)//2
        result = process(times, mid)

        if result < n:
            # mid초 안에 작업완료 불가능한 경우
            left = mid+1
        else:
            # mid초 안에 작업이 가능한 경우
            right = mid-1
            answer = mid

    return answer


print(solution(6, [7, 10]))
