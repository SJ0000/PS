
from collections import deque
from heapq import heapify, heappop, heappush
import sys


def read():
    return sys.stdin.readline().rstrip()


def remove_gt():
    if len(gt) == 0:
        return False

    selected = heappop(gt)
    # selected 제거
    s_prev = prev[selected]
    s_next = next[selected]
    if s_prev != -1:
        next[s_prev] = s_next
    if s_next != n:
        prev[s_next] = s_prev
    a[selected] = -1

    # 새로 gt가 생기는지 확인
    if s_prev != -1 and s_next != n:
        if a[s_prev] < a[s_next]:
            heappush(gt, s_prev)

    return True


def remove_loe(count):
    if count == 0:
        return
    while True:
        for target in range(0, 10):
            for i in range(n-1, -1, -1):
                if a[i] == target:
                    a[i] = -1
                    count -= 1
                    if count == 0:
                        return


n, k = map(int, read().split())

a = list(map(int, list(read())))
next = [i+1 for i in range(n)]
prev = [i-1 for i in range(n)]

gt = []
for i in range(n-1):
    if a[i] < a[i+1]:
        gt.append(i)

count = 0
for _ in range(k):
    if remove_gt():
        count += 1
    else:
        break

remove_loe(k-count)
a = list(map(str, filter(lambda x: x != -1, a)))
print(''.join(a))
