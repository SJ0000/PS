
def solution(n, s, a, b, fares):
    s -= 1
    a -= 1
    b -= 1
    graph = [[-1 for _ in range(n)] for __ in range(n)]
    d = [[-1 for _ in range(n)] for __ in range(n)]

    max_value = 987654321
    for [fr, to, fare] in fares:
        graph[fr-1][to-1] = fare
        graph[to-1][fr-1] = fare

    def dijkstra(x, y):
        if d[x][y] != -1:
            return d[x][y]

        # x -> y 최단거리
        dist = [max_value for _ in range(n)]
        visit = [False for _ in range(n)]
        dist[x] = 0

        while True:
            min_dist = max_value
            node = -1
            for i in range(n):
                if visit[i] or dist[i] == -1:
                    continue
                if min_dist > dist[i]:
                    node = i
                    min_dist = dist[i]
            # 모든 node를 탐색한 경우
            if node == -1:
                break

            visit[node] = True
            for i in range(n):
                if i == node:
                    continue
                if graph[node][i] != -1:
                    dist[i] = min(dist[i], dist[node]+graph[node][i])

        for next in range(n):
            if next == x:
                continue
            d[x][next] = dist[next]
            d[next][x] = dist[next]
        return dist[y]

    no_share = dijkstra(s, a) + dijkstra(s, b)
    # 경유지에서 갈라지는 방법
    via_stopover = max_value
    for stopover in range(n):
        if stopover == a or stopover == b or stopover == s:
            continue
        via_stopover = min(via_stopover, dijkstra(
            s, stopover) + dijkstra(stopover, a) + dijkstra(stopover, b))

    share_ab = dijkstra(s, a) + dijkstra(a, b)
    share_ba = dijkstra(s, b) + dijkstra(b, a)

    return min(no_share, via_stopover, share_ab, share_ba)


print(solution(6, 4, 6, 2, [[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [
      5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]))


# graph = [[-1, 15, -1, 35, -1, -1], [15, -1, 5, 10, -1, -1], [-1, 5, -1, -1, -1, -1],
#         [35, 10, -1, -1, 5, -1], [-1, -1, -1, 5, -1, 8], [-1, -1, -1, -1, 8, -1]]
#print(dijkstra(0, 5, graph))
