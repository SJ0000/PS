
from collections import deque

import sys


def read():
    return sys.stdin.readline().rstrip()


N = int(read())
x = list(map(int, read().split()))
x.sort()
index = (N//2)-1 if N % 2 == 0 else N//2
print(x[index])
