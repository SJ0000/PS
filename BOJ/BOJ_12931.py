
from collections import deque
import heapq

import sys


def read():
    return sys.stdin.readline().rstrip()


_ = int(read())
b = list(map(int, read().split()))
b = list(filter(lambda x: x > 0, b))
n = len(b)
a = b[:]

count = 0
while sum(a) != n:
    for i in range(n):
        if a[i] == 1:
            continue
        if a[i] % 2 == 1:
            count += 1
        a[i] //= 2
    count += 1
count += n
print(count)
