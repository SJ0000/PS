def get_component_count(g):
    n = len(g)
    visit = [False for _ in range(n)]

    def dfs(node):
        if visit[node]:
            return
        visit[node] = True
        for next in range(n):
            if next == n:
                continue
            if g[node][next] == 1:
                dfs(next)

    component_count = 0
    for node in range(n):
        if visit[node]:
            continue
        dfs(node)
        component_count += 1

    return component_count


def solution(n, costs):
    g = [[0 for _ in range(n)] for __ in range(n)]
    costs.sort(key=lambda x: x[2])

    total_cost = 0
    before_component_count = n
    for [x, y, cost] in costs:
        total_cost += cost
        g[x][y] = 1
        g[y][x] = 1
        component_count = get_component_count(g)
        if component_count == before_component_count:
            total_cost -= cost
            g[x][y] = 0
            g[y][x] = 0
        if component_count == 1:
            break
        before_component_count = component_count

    return total_cost


print(solution(4, [[0, 1, 1], [0, 2, 2], [1, 2, 5], [1, 3, 1], [2, 3, 8]]))
