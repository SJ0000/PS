def solution(n, s):

    x = s//n
    if x == 0:
        return [-1]

    mod = s % n

    answer = [x for i in range(n-mod)] + [x+1 for i in range(mod)]

    return answer


print(solution(2, 1))
