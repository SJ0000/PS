
from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def process(a):
    n = len(a)
    for i in range(n-1):
        a[i+1] += a[i]//2
        a[i] %= 2


def buy(a):
    n = len(a)

    for i in range(n-1):
        if a[i] != 0:
            a[i] += 1
            return 1 << i


N, K = map(int, read().split())

# 물이 2^n만큼 들어있는 물병의 갯수
a = [0 for _ in range(25)]
a[0] = N

bottles = 0
while True:
    process(a)
    if sum(a) <= K:
        break
    bottles += buy(a)


print(bottles)
