
from collections import deque
from itertools import permutations


positions = [[] for _ in range(7)]


def solution(board, r, c):
    global positions

    card_count = 0
    for i in range(4):
        for j in range(4):
            if board[i][j] != 0:
                positcount = max(card_count, board[i][j])

    li = [i for i in range(1, card_count+1)]
    answer = 987654321

    for sequence in permutations(li):
        copied = copy_board(board)
        answer = min(answer, process(copied, (r, c), sequence))

    return answer


def copy_board(board):
    copied = []
    for row in board:
        copied.append(row[:])
    return copied


def process(board, start, sequence):
    global positions
    if len(sequence) == 0:
        return 0

    next = sequence[0]
    p1 = positions[next][0]
    p2 = positions[next][1]

    # Enter 포함
    (ax, ay) = p1
    (bx, by) = p2

    board[ax][ay] = 0
    board[bx][by] = 0

    result1 = cost(board, start, p1) + cost(board, p1, p2) + \
        2 + process(board, p2, sequence[1:])

    result2 = cost(board, start, p2) + cost(board, p2, p1) + \
        2 + process(board, p1, sequence[1:])
    board[ax][ay] = next
    board[bx][by] = next
    return min(result1, result2)


def cost(board, fr, to):
    q = deque()
    visit = [[False for _ in range(4)] for __ in range(4)]
    moves = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    q.append(fr)
    visit[fr[0]][fr[1]] = True

    def can_visit(x, y):
        if not (0 <= x < 4 and 0 <= y < 4):
            return False
        return not visit[x][y]

    count = 0

    while len(q) > 0:
        for _ in range(len(q)):
            (x, y) = q.popleft()
            if (x, y) == to:
                return count

            for (dx, dy) in moves:
                # 이동
                ax = x + dx
                ay = y + dy
                if can_visit(ax, ay):
                    visit[ax][ay] = True
                    q.append((ax, ay))
                # ctrl + 이동
                # 0이 아닌게 나올때까지 이동
                while 0 <= ax < 4 and 0 <= ay < 4 and board[ax][ay] == 0:
                    ax += dx
                    ay += dy
                    if (ax, ay) == to:
                        q.append(to)

                if not (0 <= ax < 4 and 0 <= ay < 4):
                    ax -= dx
                    ay -= dy
                if can_visit(ax, ay):
                    visit[ax][ay] = True
                    q.append((ax, ay))
        count += 1
    return 0


print(solution([[1, 0, 0, 3], [2, 0, 0, 0], [0, 0, 0, 2], [3, 0, 1, 0]], 1, 0))

#board = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
#print(cost(board, (3, 2), (1, 0)))
