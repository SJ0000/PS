
import sys


def read():
    return sys.stdin.readline().rstrip()


n, s, r = map(int, read().split())
damaged = set(map(int, read().split()))
extra = list(map(int, read().split()))

extra.sort()
# 우선순위 : 나, 왼쪽, 오른쪽
for x in extra:
    if x in damaged:
        damaged.discard(x)
        continue
    if x-1 in damaged:
        damaged.discard(x-1)
        continue
    if x+1 in damaged:
        damaged.discard(x+1)

print(len(damaged))
