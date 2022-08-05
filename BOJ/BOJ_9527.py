

import sys


def read():
    return sys.stdin.readline().rstrip()


def go(x):
    global d
    if x <= 1:
        return x
    i = 0
    while x > ((1 << i)-1):
        i += 1
    i -= 1
    if x == (1 << i)-1:
        return d[i]

    remain = x-((1 << i)-1)
    return d[i] + remain + go(remain-1)


d = [0 for _ in range(55)]
d[1] = 1
for i in range(2, 55):
    d[i] = (2**(i-1)) + (2*d[i-1])


a, b = map(int, read().split())
print(go(b)-go(a-1))
