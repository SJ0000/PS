

def solution(triangle):
    height = len(triangle)
    d = [[-1 for _ in range(height)] for __ in range(height)]

    d[0][0] = triangle[0][0]
    for h in range(1, height):
        for w in range(h+1):
            d[h][w] = max(d[h][w], d[h-1][w]+triangle[h][w])
            if w-1 >= 0:
                d[h][w] = max(d[h][w], d[h-1][w-1]+triangle[h][w])

    # print(d)

    return max(d[height-1])


print(solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]))
