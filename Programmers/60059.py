from collections import deque


def rotate90(key):
    copied = key[:]
    copied.reverse()
    return list(map(list, zip(*copied)))


def size_up(key, n):
    m = len(key)
    if n == m:
        return key

    diff = n-m
    new_key = []
    added_row = [0 for _ in range(diff)]
    for row in key:
        new_key.append(row + added_row)

    zero_row = [0 for _ in range(n)]
    for i in range(diff):
        new_key.append(zero_row)

    return new_key


def move_up(key):
    n = len(key)
    new_key = []
    for i in range(1, n):
        new_key.append(key[i])
    new_key.append([0 for i in range(n)])
    return new_key


def move_down(key):
    n = len(key)
    new_key = []
    new_key.append([0 for i in range(n)])
    for i in range(n-1):
        new_key.append(key[i])

    return new_key


def move_right(key):
    n = len(key)
    new_key = []
    for row in key:
        new_key.append([0]+row[:n-1])
    return new_key


def move_left(key):
    n = len(key)
    new_key = []
    for row in key:
        new_key.append(row[1:]+[0])
    return new_key


def is_matched(key, lock):
    '''
    print("is matched")
    for i in range(len(key)):
        print(key[i], "     ", lock[i])
    '''
    n = len(key)
    for i in range(n):
        for j in range(n):
            if key[i][j] == lock[i][j]:
                return False
    return True


# l,u / l,d / r,u / r,d
def simulate(key, lock, left_or_right, up_or_down):
    n = len(lock)
    visit = [[[False for _ in range(n+1)]
              for __ in range(n+1)] for _____ in range(4)]

    q = deque()
    rotated_key1 = rotate90(key)
    rotated_key2 = rotate90(rotated_key1)
    rotated_key3 = rotate90(rotated_key2)

    q.append((key, 0, 0, 0))
    q.append((rotated_key1, 1, 0, 0))
    q.append((rotated_key2, 2, 0, 0))
    q.append((rotated_key3, 3, 0, 0))

    while len(q) > 0:
        (current_key, rotate_count, lr, ud) = q.popleft()

        if lr > n or ud > n:
            continue

        if visit[rotate_count][lr][ud]:
            continue

        visit[rotate_count][lr][ud] = True

        if is_matched(current_key, lock):
            return True

        if left_or_right == 'left':
            q.append((move_left(current_key), rotate_count, lr+1, ud))
        else:
            q.append((move_right(current_key), rotate_count, lr+1, ud))

        if up_or_down == 'up':
            q.append((move_up(current_key), rotate_count, lr, ud+1))
        else:
            q.append((move_down(current_key), rotate_count, lr, ud+1))

    return False


def solution(key, lock):

    key = size_up(key, len(lock))

    # l,u / l,d / r,u / r,d
    if simulate(key, lock, 'left', 'up'):
        return True
    if simulate(key, lock, 'left', 'down'):
        return True
    if simulate(key, lock, 'right', 'up'):
        return True
    if simulate(key, lock, 'right', 'down'):
        return True

    return False


key = [[1, 1, 1, 1], [2, 1, 1, 1], [3, 1, 1, 1], [4, 1, 1, 1]]
lock = [[1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 0]]

print(solution(key, lock))
