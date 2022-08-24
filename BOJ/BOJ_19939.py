
from collections import deque
import heapq

import sys


def read():
    return sys.stdin.readline().rstrip()


def solution(n, k):
    if (k*(k+1))//2 > n:
        return -1
    # 1) 1 ~ K 개 분배
    n -= (k*(k+1))//2
    # 2) 모든 팀에 1개씩 분배
    n %= k

    return k-1 if n == 0 else k


n, k = map(int, read().split())

# 가능 여부 판단
print(solution(n, k))
