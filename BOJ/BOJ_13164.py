
from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


n, k = map(int, read().split())
a = list(map(int, read().split()))

d = []
for i in range(1, n):
    d.append(a[i]-a[i-1])
d.sort()
for _ in range(k-1):
    d.pop()
print(sum(d))
