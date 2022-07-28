

import sys


def read():
    return sys.stdin.readline().rstrip()

# 2가지 용액을 고른 후, 나머지 1개를 이분탐색


def search(first, second):
    global n, a
    base = a[first] + a[second]

    l = second+1
    r = n-1

    selected = 3000000001
    while l <= r:
        mid = (l+r)//2
        mixed = base + a[mid]
        # 갱신
        if abs(mixed) < abs(selected):
            selected = mixed

        # 탐색
        if mixed < 0:
            l = mid+1
        else:
            r = mid-1

    return selected


n = int(read())
a = list(map(int, read().split()))
a.sort()

close_to_zero = 3000000001
answer = []
for first in range(n-2):
    for second in range(first+1, n-1):
        result = search(first, second)
        if abs(result) < abs(close_to_zero):
            close_to_zero = result
            answer = [a[first], a[second], result-a[first]-a[second]]

print(' '.join(list(map(str, answer))))
