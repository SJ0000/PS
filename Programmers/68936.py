# 2차원 배열을 4개로 쪼개고 list에 담아서 반환
def divide(arr):
    n = len(arr)//2
    sub1 = []
    sub2 = []
    sub3 = []
    sub4 = []

    for i in range(n):
        sub1.append(arr[i][:n])
        sub2.append(arr[i][n:])
    for i in range(n, 2*n):
        sub3.append(arr[i][:n])
        sub4.append(arr[i][n:])

    return [sub1, sub2, sub3, sub4]


def compress(arr):
    # 더이상 압축이 불가능 한 경우
    if len(arr) == 1:
        return arr

    # 압축 가능한 경우
    count = 0
    for row in arr:
        count += sum(row)

    if count == 0:
        return [0]

    if count == len(arr)**2:
        return [1]

    # 압축실패시 4등분
    result = []
    sub_arrays = divide(arr)
    for sub_array in sub_arrays:
        result.append(compress(sub_array))

    return result


def counting(arr):
    if len(arr) == 1:
        if arr[0] == 0:
            return (1, 0)
        elif arr[0] == 1:
            return (0, 1)
        else:
            return counting(arr[0])

    total_zero = 0
    total_one = 0
    for sub in arr:
        (zero_count, one_count) = counting(sub)
        total_zero += zero_count
        total_one += one_count

    return (total_zero, total_one)


def solution(arr):
    compressed = compress(arr)
    return counting(compressed)


print(solution([[1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 1, 1, 1, 1], [0, 1, 0, 0, 1, 1, 1, 1], [
    0, 0, 0, 0, 0, 0, 1, 1], [0, 0, 0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 1, 0, 0, 1], [0, 0, 0, 0, 1, 1, 1, 1]]))
