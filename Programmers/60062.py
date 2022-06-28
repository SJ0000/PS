from collections import deque
from itertools import permutations


def solution(n, weak, dist):
    dist = sorted(dist, reverse=True)
    for i in range(1, n+1):
        if simulation(n, dist, i, weak):
            return i

    return -1


# 모든 dist 순서에서 move
# dist의 첫 i명만 사용
def simulation(n, dist, i, weak):
    rotated_weak = deque(weak)
    for seq in permutations(dist, i):
        for i in range(len(weak)-1):
            if move(seq, rotated_weak):
                return True
            # rotate
            first = rotated_weak.popleft()
            rotated_weak.append(first + n)

    return False
# dist에서 차례대로 weak 방문 했을 때 전부 점검 가능한지 여부


def move(dist, weak):
    i = 0
    end = weak[0] + dist[i]
    for w in weak:
        if w > end:
            i += 1
            if i >= len(dist):
                return False
            end = w+dist[i]
    return True


print(solution(12, [1, 3, 4, 9, 10], [3, 5, 7]))
