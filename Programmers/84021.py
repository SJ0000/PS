
def solution(game_board, table):

    blocks = get_blocks(table)

    for block in blocks:
        match(game_board, block)

    answer = 0
    for row in game_board:
        for item in row:
            if item == 2:
                answer += 1

    return answer


def get_blocks(table):
    n = len(table)
    visit = [[False for _ in range(n)] for __ in range(n)]
    moves = [(0, -1), (0, 1), (-1, 0), (1, 0)]
    blocks = []
    block = []

    def can_move(x, y):
        if not (0 <= x < n and 0 <= y < n):
            return False
        if visit[x][y]:
            return False
        return table[x][y] == 1

    def dfs(x, y):
        visit[x][y] = True
        block.append((x, y))
        for (dx, dy) in moves:
            ax = x+dx
            ay = y+dy
            if can_move(ax, ay):
                dfs(ax, ay)

    def to_array(block):
        li = []
        dx = block[0][0]
        dy = min(list(map(lambda xy: xy[1], block)))
        for (x, y) in block:
            li.append((x-dx, y-dy))

        xlist = list(map(lambda xy: xy[0], li))
        ylist = list(map(lambda xy: xy[1], li))

        height = max(xlist)+1
        width = max(ylist)-min(ylist)+1

        new_block = [[0 for _ in range(width)] for __ in range(height)]

        for (x, y) in li:
            new_block[x][y] = 2

        return new_block

    for i in range(n):
        for j in range(n):
            if can_move(i, j):
                block = []
                dfs(i, j)
                blocks.append(to_array(block))

    return blocks


def match(board, block):
    n = len(board)
    moves = [(0, -1), (0, 1), (-1, 0), (1, 0)]

    def rotate90(block):
        return list(zip(*block[::-1]))

    def has_space(x, y):
        for i in range(len(block)):
            for j in range(len(block[0])):
                ax = x+i
                ay = y+j
                if board[ax][ay] >= 1 and block[i][j] == 2:
                    return False
        return True

    def is_correct_match(x, y):
        for i in range(len(block)):
            for j in range(len(block[0])):
                ax = x+i
                ay = y+j
                if block[i][j] != 2:
                    continue
                for move in moves:
                    mx = ax + move[0]
                    my = ay + move[1]
                    if not (0 <= mx < n and 0 <= my < n):
                        continue
                    if board[mx][my] == 0:
                        return False
        return True

    def insert(x, y):
        for i in range(len(block)):
            for j in range(len(block[0])):
                ax = x+i
                ay = y+j
                board[ax][ay] += block[i][j]

    def rollback(x, y):
        for i in range(len(block)):
            for j in range(len(block[0])):
                ax = x+i
                ay = y+j
                board[ax][ay] -= block[i][j]

    for rotate_count in range(4):
        block = rotate90(block)
        for i in range(n-len(block)+1):
            for j in range(n-len(block[0])+1):
                if has_space(i, j):
                    insert(i, j)
                    if not is_correct_match(i, j):
                        rollback(i, j)
                        continue
                    return


print(solution([[1, 1, 0, 0, 1, 0], [0, 0, 1, 0, 1, 0], [0, 1, 1, 0, 0, 1], [1, 1, 0, 1, 1, 1], [1, 0, 0, 0, 1, 0], [0, 1, 1, 1, 0, 0]], [[1, 0, 0, 1, 1, 0], [1, 0, 1, 0, 1, 0], [0, 1, 1, 0, 1, 1], [
    0, 0, 1, 0, 0, 0], [1, 1, 0, 1, 1, 0], [0, 1, 0, 0, 0, 0]]))

print(solution([[0, 0, 0], [1, 1, 0], [1, 1, 1]],
      [[1, 1, 1], [1, 0, 0], [0, 0, 0]]))
