def solution(board):

    width = len(board[0])  # j
    height = len(board)  # i

    for i in range(1, height):
        for j in range(1, width):
            if board[i][j] == 0:
                continue
            board[i][j] = min(board[i-1][j], board[i][j-1], board[i-1][j-1])+1

    print(board)

    max_length = 0
    for row in board:
        max_length = max(max_length, max(row))

    return max_length**2


print(solution([[0, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1], [0, 0, 1, 0]]))
