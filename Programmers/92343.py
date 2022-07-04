def solution(info, edges):
    n = len(info)
    visit = [[[[False for _ in range(n+1)] for __ in range(n+1)]
             for ___ in range(n+1)] for ____ in range(n)]
    g = [[] for _ in range(n)]

    for (x, y) in edges:
        g[x].append(y)
        g[y].append(x)

    answer = [0]

    # 해당 노드에 같은 sheep,wolf로 왔는데, 전혀 다른 경로로 왔을 경우도 있음
    def dfs(node, sheep, wolf, visit_history):
        if visit[node][sheep][wolf][max(visit_history)]:
            return
        if sheep <= wolf:
            return

        visit[node][sheep][wolf][max(visit_history)] = True

        answer[0] = max(answer[0], sheep)
        # print("node", node, (sheep, wolf), visit_history)

        for next in g[node]:
            if not next in visit_history:
                visit_history.add(next)
                if info[next] == 0:
                    dfs(next, sheep+1, wolf, visit_history)
                else:
                    dfs(next, sheep, wolf+1, visit_history)
                visit_history.discard(next)
            else:
                dfs(next, sheep, wolf, visit_history)

    dfs(0, 1, 0, {0})

    return answer[0]


info = [0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1]
edges = [[0, 1], [1, 2], [1, 4], [0, 8], [8, 7], [
    9, 10], [9, 11], [4, 3], [6, 5], [4, 6], [8, 9]]
print("answer", solution(info, edges))
