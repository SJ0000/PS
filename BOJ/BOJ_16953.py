

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def solution(a, b):
    q = deque()
    q.append(a)
    count = 1
    while len(q) > 0:
        for _ in range(len(q)):
            current = q.popleft()
            if current == b:
                return count
            next = [current*2, current*10+1]
            for n in next:
                if n <= b:
                    q.append(n)

        count += 1

    return -1


A, B = map(int, read().split())
print(solution(A, B))
