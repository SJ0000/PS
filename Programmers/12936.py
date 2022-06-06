

factorials = [-1 for i in range(21)]
factorials[0] = factorials[1] = 1


def factorial(i):
    if factorials[i] != -1:
        return factorials[i]
    factorials[i] = i * factorial(i-1)
    return factorials[i]


def solution(n, k):

    # li부터 시작해서 만들 수 있는 k번째 순열의 첫번째 값
    def get_first(li, count):
        return li[count//factorial(len(li)-1)]

    perm = [i for i in range(1, n+1)]
    answer = []
    k -= 1  # 0번부터 시작하도록 로직을 구현했음
    while len(perm) > 0:
        first = get_first(perm, k)
        answer.append(first)
        k %= factorial(len(perm)-1)
        perm.remove(first)

    return answer


print(solution(4, 11))
