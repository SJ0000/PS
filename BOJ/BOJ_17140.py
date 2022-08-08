

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def sort_array(li):
    nums = [0 for _ in range(101)]
    for item in li:
        nums[item] += 1
    temp = []
    for i in range(1, 101):
        if nums[i] == 0:
            continue
        temp.append((nums[i], i))
    temp.sort()
    result = []
    for i in range(0, min(len(temp), 50)):
        (count, value) = temp[i]
        result.append(value)
        result.append(count)
    return result


def operation_R(rows, columns):
    global A
    max_columns = 0
    for i in range(rows):
        sorted = sort_array(A[i])
        for j in range(len(sorted)):
            A[i][j] = sorted[j]
        for j in range(len(sorted), 100):
            A[i][j] = 0
        max_columns = max(max_columns, len(sorted))

    return max_columns


def operation_C(rows, columns):
    global A
    max_rows = 0
    for i in range(columns):
        temp = []
        for j in range(rows):
            temp.append(A[j][i])
        sorted = sort_array(temp)
        max_rows = max(max_rows, len(sorted))
        for j in range(len(sorted)):
            A[j][i] = sorted[j]
        for j in range(len(sorted), 100):
            A[j][i] = 0
    return max_rows


N = 100
r, c, k = map(int, read().split())
A = [[0 for _ in range(N)] for _ in range(N)]
for i in range(3):
    arr = list(map(int, read().split()))
    for j in range(3):
        A[i][j] = arr[j]

rows, columns = 3, 3
answer = -1
for time in range(101):
    if A[r-1][c-1] == k:
        answer = time
        break

    if rows >= columns:
        columns = operation_R(rows, columns)
    else:
        rows = operation_C(rows, columns)

print(answer)
