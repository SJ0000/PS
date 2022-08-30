
from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def move(books, m):
    dist = 0
    while True:
        if len(books) == 0:
            return dist
        dist += books[-1]*2
        for i in range(m):
            if len(books) != 0:
                books.pop()


n, m = map(int, read().split())
a = list(map(int, read().split()))
x = []
y = []
for item in a:
    if item > 0:
        x.append(item)
    else:
        y.append(-item)

x.sort()
y.sort()

last = 0
if len(x) == 0:
    last = y[-1]
elif len(y) == 0:
    last = x[-1]
else:
    last = max(x[-1], y[-1])

print(move(x, m) + move(y, m)-last)
