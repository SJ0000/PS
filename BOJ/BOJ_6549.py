
from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def solve(l, r):
    global a
    if l == r:
        return a[l]

    mid = (l+r)//2
    # 분할정복
    result = max(solve(l, mid), solve(mid+1, r))

    # 걸치는 경우
    # 사각형이 입력 전체를 덮을 때까지 확장
    lo, hi = mid, mid+1
    height = min(a[lo], a[hi])
    result = max(result, height*2)
    while l <= lo and hi <= r:
        if l == lo and hi == r:
            break
        if l == lo:
            hi += 1
            height = min(height, a[hi])
        elif hi == r:
            lo -= 1
            height = min(height, a[lo])
        elif l < lo and hi < r:
            if a[lo-1] < a[hi+1]:
                hi += 1
                height = min(height, a[hi])
            else:
                lo -= 1
                height = min(height, a[lo])
        # print(l, r, lo, hi, height*(hi-lo+1))
        result = max(result, height * (hi-lo+1))
    return result


while True:
    a = list(map(int, read().split()))
    if len(a) == 1 and a[0] == 0:
        break
    a = a[1:]
    print(solve(0, len(a)-1))
