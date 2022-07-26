

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def solution(a):
    global n
    MIN_VALUE = 2000000001

    def binary_search(x, start):
        l = start
        r = n-1
        prev_value = MIN_VALUE
        prev_mid = -1
        while l <= r:
            mid = (l+r)//2
            value = x+a[mid]
            if value == 0:
                return a[mid]
            if abs(value) <= prev_value:
                prev_value = abs(value)
                prev_mid = mid

            if value < 0:
                l = mid+1
            else:
                r = mid-1

        return a[prev_mid]

    result = []
    for i in range(n-1):
        x = a[i]
        y = binary_search(x, i+1)
        result.append((x, y))

    min_value = MIN_VALUE
    for (x, y) in result:
        value = abs(x+y)
        if value < min_value:
            min_value = value
    for (x, y) in result:
        if abs(x+y) == min_value:
            return (x, y)

    return (0, 0)


n = int(read())
a = list(map(int, read().split()))

result = solution(a)
print(str(result[0])+' '+str(result[1]))
