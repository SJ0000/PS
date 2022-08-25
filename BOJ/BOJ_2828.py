
from collections import deque
import heapq

import sys


def read():
    return sys.stdin.readline().rstrip()


N, M = map(int, read().split())
J = int(read())

st = 1
answer = 0
for _ in range(J):
    a = int(read())
    ed = st+M-1
    if a < st:
        move = st-a
        answer += move
        st -= move
    elif ed < a:
        move = a-ed
        answer += move
        st += move
print(answer)
