def solution(land):

    d = [[0 for _ in range(4)] for _ in range(len(land))]

    # d[i][j] = i행 j칸에서 얻을 수 있는 최대 값
    # d[i][j] = land[i][j] + max(d[i-1][x],d[i-1][y],d[i-1][z])
    #           (x,y,z 는 0,1,2,3 중 j를 제외한 3가지 숫자)

    def get_max_without_j(row, j):
        max_value = 0
        for x in range(4):
            if x == j:
                continue
            max_value = max(max_value, d[row][x])
        return max_value

    d[0] = land[0]
    for i in range(1, len(d)):
        for j in range(4):
            d[i][j] = land[i][j] + get_max_without_j(i-1, j)

    return max(d[len(d)-1])


print(solution([[1, 2, 3, 5], [5, 6, 7, 8], [4, 3, 2, 1]]))
