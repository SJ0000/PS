
from collections import deque

import sys


def read():
    return sys.stdin.readline().rstrip()


n, w = map(int, read().split())
a = []
for _ in range(n):
    a.append(int(read()))
a.append(0)

money = w
coins = 0
prev_price = 51
for i in range(0, len(a)-1):
    # 저점
    if prev_price > a[i] < a[i+1]:
        coins += money//a[i]
        money %= a[i]
    # 고점
    if prev_price < a[i] > a[i+1]:
        money += coins*a[i]
        coins = 0

    if a[i] != a[i+1]:
        prev_price = a[i]

print(money)
