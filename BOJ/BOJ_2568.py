

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def find_index(a, value):
    # 나보다 큰것 중 가장 가장 작은 값의 인덱스
    l = 0
    r = len(a)-1
    result = -1
    while l <= r:
        mid = (l+r)//2
        if a[mid] > value:
            result = mid
            r = mid-1
        else:
            l = mid+1
    return result


def solution(a):
    n = len(a)
    lis = [a[0]]
    k = [0 for _ in range(n)]
    for i in range(1, n):
        index = -1
        if lis[-1] < a[i]:
            lis.append(a[i])
            index = len(lis)-1
        else:
            index = find_index(lis, a[i])
            lis[index] = a[i]
        k[i] = index

    result = [False for _ in range(n)]
    current = len(lis)-1
    for i in range(n-1, -1, -1):
        if k[i] == current:
            result[i] = True
            current -= 1
        if current == -1:
            break
    return result


N = int(read())

info = []
for _ in range(N):
    x, y = map(int, read().split())
    info.append((x, y))

a = [0 for _ in range(N)]
b = [0 for _ in range(N)]
info.sort()
for i in range(N):
    a[i] = info[i][0]
    b[i] = info[i][1]

alive = solution(b)
answer = []
for i in range(N):
    if not alive[i]:
        answer.append(a[i])

print(len(answer))
for item in answer:
    print(item)
