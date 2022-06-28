def solution(n, build_frame):

    pillars = [[0 for _ in range(n+1)] for __ in range(n+1)]
    beams = [[0 for _ in range(n+1)] for __ in range(n+1)]

    def can_add_pillar(x, y):
        # 벽면을 벗어나게 기둥을 설치하는 경우
        if y < 0 or y >= n or x < 0 or x > n:
            return False
        # 바닥 위
        if y == 0:
            return True
        # 다른 기둥 위
        if pillars[x][y-1] == 1:
            return True
        # 보의 한쪽 끝 부분 위
        if beams[x-1][y] + beams[x][y] >= 1:
            return True

        return False

    def can_add_beam(x, y):
        # 벽면을 벗어나게 보를 설치하는 경우
        if x >= n or x < 0 or y < 0 or y > n:
            return False
        # 바닥에 보를 설치하는 경우
        if y == 0:
            return False

        # 한쪽 끝이 기둥 위
        if pillars[x][y-1] + pillars[x+1][y-1] >= 1:
            return True
        # 양쪽 끝 부분이 다른 보와 동시에 연결
        if beams[x+1][y] + beams[x-1][y] == 2:
            return True

        return False

    def is_possible(connected_pillars, connected_beams):
        for (x, y) in connected_pillars:
            if pillars[x][y] == 0:
                continue
            if not can_add_pillar(x, y):
                return False

        for (x, y) in connected_beams:
            if beams[x][y] == 0:
                continue
            if not can_add_beam(x, y):
                return False
        return True

    def remove_pillar_if_possible(x, y):
        pillars[x][y] = 0

        connected_pillars = [(x, y+1)]
        connected_beams = [(x-1, y+1), (x, y+1)]
        if not is_possible(connected_pillars, connected_beams):
            pillars[x][y] = 1

    def remove_beam_if_possible(x, y):
        beams[x][y] = 0

        connected_pillars = [(x, y), (x+1, y)]
        connected_beams = [(x-1, y), (x+1, y)]
        if not is_possible(connected_pillars, connected_beams):
            beams[x][y] = 1

    for [x, y, a, b] in build_frame:
        if a == 0 and b == 0:
            remove_pillar_if_possible(x, y)
        elif a == 0 and b == 1:
            if can_add_pillar(x, y):
                pillars[x][y] = 1
        elif a == 1 and b == 0:
            remove_beam_if_possible(x, y)
        else:
            if can_add_beam(x, y):
                beams[x][y] = 1

    answer = []

    for i in range(n+1):
        for j in range(n+1):
            if pillars[i][j] == 1:
                answer.append([i, j, 0])
            if beams[i][j] == 1:
                answer.append([i, j, 1])

    return answer


print(solution(5, [[0, 0, 0, 1], [2, 0, 0, 1], [4, 0, 0, 1], [0, 1, 1, 1], [
      1, 1, 1, 1], [2, 1, 1, 1], [3, 1, 1, 1], [2, 0, 0, 0], [1, 1, 1, 0], [2, 2, 0, 1]]))
