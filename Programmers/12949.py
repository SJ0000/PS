def solution(arr1, arr2):

    # arr1의 a-1행과 arr2의 b-1열의 곱
    def multiple(a, b):
        row = arr1[a]
        col = list(map(lambda x: x[b], arr2))
        ret = 0
        for i in range(len(row)):
            ret += row[i]*col[i]
        return ret

    answer = []

    for i in range(len(arr1)):
        answer.append([])
        for j in range(len(arr2[0])):
            answer[i].append(multiple(i, j))

    return answer


print(solution([[2, 3, 2], [4, 2, 4], [3, 1, 4]],
      [[5, 4, 3], [2, 4, 1], [3, 1, 1]]))
