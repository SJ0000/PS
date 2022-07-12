

import sys


def read():
    return sys.stdin.readline().rstrip()


def recursive(N, r, c):
    global li
    half = (2**(N-1))
    if N == 0:
        return
    # 1
    if r < half and c < half:
        li.insert(0, 0)
        recursive(N-1, r, c)
    # 2
    if r < half and c >= half:
        li.insert(0, 1)
        recursive(N-1, r, c-half)
    # 3
    if r >= half and c < half:
        li.insert(0, 2)
        recursive(N-1, r-half, c)
    # 4
    if r >= half and c >= half:
        li.insert(0, 3)
        recursive(N-1, r-half, c-half)


N, r, c = map(int, read().split())
li = []

recursive(N, r, c)
print(li)
answer = 0
for (i, value) in enumerate(li):
    answer += (4**i)*value
print(answer)
