

import sys


def read():
    return sys.stdin.readline().rstrip()


N, M = map(int, read().split())
truth = [False for _ in range(N+1)]
g = [[0 for _ in range(N+1)] for __ in range(N+1)]
parties = []
truth_info = list(map(int, read().split()))
for i in range(1, len(truth_info)):
    truth[truth_info[i]] = True

for _ in range(M):
    party = list(map(int, read().split()))[1:]
    first = party[0]
    for participant in party:
        g[first][participant] = 1
        g[participant][first] = 1
    parties.append(party)

for u in range(N+1):
    for k in range(N+1):
        if g[u][k] == 0:
            continue
        for v in range(N+1):
            if g[k][v] == 1:
                g[u][v] = 1
                g[v][u] = 1


for i in range(N+1):
    for j in range(N+1):
        if truth[i] and g[i][j] == 1:
            truth[j] = True


result = 0
for party in parties:
    can_lie = True
    for x in party:
        if truth[x]:
            can_lie = False
            break
    if can_lie:
        result += 1
print(result)
