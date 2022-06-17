def solution(n, cores):

    def total_process(time):
        result = 0
        for core in cores:
            result += time//core
            if time % core != 0:
                result += 1
        return result

    # 작업 시간을 이분탐색
    l = 0
    r = 10000*50000
    while l < r:
        mid = (l+r)//2
        process = total_process(mid)

        if process >= n:
            r = mid
        else:
            l = mid+1

    time = l
    li = []
    for (i, core) in enumerate(cores):
        if (time-1) % core == 0:
            li.append(i+1)

    diff = total_process(time) - n

    return li[len(li)-1-diff]


print(solution(6, [1, 2, 3]))
