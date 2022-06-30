def solution(sticker):
    n = len(sticker)

    if n == 1:
        return sticker[0]
    if n == 2:
        return max(sticker)

    # d[i][0] : 첫 스티커를 뜯고 진행
    # d[i][1] : 첫 스티커를 뜯지 않고 진행

    d = [[0, 0] for _ in range(n)]
    d[0][0] = sticker[0]
    d[1][0] = max(sticker[0], sticker[1])
    # 첫 스티커를 뜯은 경우 마지막 스티커를 뜯을 수 없음
    for i in range(2, n-1):
        # i번 스티커를 뜯는 경우, 뜯지 않는 경우
        d[i][0] = max(d[i-2][0] + sticker[i], d[i-1][0])
    d[n-1][0] = d[n-2][0]

    d[0][1] = 0
    d[1][1] = sticker[1]
    for i in range(2, n):
        d[i][1] = max(d[i-2][1] + sticker[i], d[i-1][1])

    return max(d[n-1])


print(solution([1, 3, 2, 5, 4]))
