

def solution(n, computers):
    visit = [False for _ in range(n)]

    def dfs(node):
        visit[node] = True

        for i in range(n):
            if node == i:
                continue

            if computers[node][i] == 1 and not visit[i]:
                dfs(i)

    networks = 0
    for i in range(n):
        if not visit[i]:
            dfs(i)
            networks += 1

    return networks


print(solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]))
