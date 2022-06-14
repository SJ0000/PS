

# 작업을 진행하고 남은 n을 반환
def process(n, works):

    max = works[0]
    max_list = []
    second_max = 0

    if max == 0:
        return 0

    for (index, value) in enumerate(works):
        if value == max:
            max_list.append(index)
        else:
            second_max = value
            break

    required_n = (max-second_max)*len(max_list)
    if n >= required_n:
        for i in max_list:
            works[i] = second_max
        return n-required_n

    diff = n//len(max_list)

    # 다 나누는게 불가능한 경우 뺄 수 있는 만큼 1씩 제거
    # 남은게 없으니 return 0
    if diff == 0:
        for i in range(n):
            works[max_list[len(max_list)-1-i]] -= 1
        return 0

    for i in max_list:
        works[i] -= diff
    return n % len(max_list)


def solution(n, works):
    works.sort(reverse=True)

    while n > 0:
        n = process(n, works)

    # print(works)
    answer = 0
    for work in works:
        answer += work**2

    return answer


# print("answer", solution(250, [100, 100, 100]))
print("answer", solution(4, [4, 3, 3]))
print("answer", solution(1, [2, 1, 2]))
print("answer", solution(3, [1, 1]))
