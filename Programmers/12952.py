answer = 0


def solution(n):

    visit = [[0 for _ in range(n)] for __ in range(n)]

    def check_and_get_check_point(checked, i, j):
        check_point = []
        # check i,j
        for x in range(n):
            if checked[i][x] == 0:
                checked[i][x] = 1
                check_point.append((i, x))
            if checked[x][j] == 0:
                checked[x][j] = 1
                check_point.append((x, j))

        left = j
        right = j
        for x in range(i+1, n):
            left -= 1
            right += 1
            if left >= 0:
                if checked[x][left] == 0:
                    checked[x][left] = 1
                    check_point.append((x, left))
            if right < n:
                if checked[x][right] == 0:
                    checked[x][right] = 1
                    check_point.append((x, right))

        return check_point

    def rollback_visit(check_point):
        for (i, j) in check_point:
            visit[i][j] = 0

    def dfs(row_index):
        global answer
        if row_index == n:
            answer += 1
            return

        for j in range(n):
            if visit[row_index][j] == 0:
                check_point = check_and_get_check_point(visit, row_index, j)
                dfs(row_index+1)
                rollback_visit(check_point)

    dfs(0)

    return answer


print(solution(12))
