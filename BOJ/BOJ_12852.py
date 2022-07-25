

from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def solution(n):
    q = deque()
    visit = set()
    q.append((n, [n]))

    while len(q) > 0:
        (value, prev) = q.popleft()
        if value == 1:
            return prev
        nexts = [value-1]
        if value % 3 == 0:
            nexts.append(value//3)
        if value % 2 == 0:
            nexts.append(value//2)
        for next in nexts:
            if not next in visit:
                visit.add(next)
                q.append((next, prev[:]+[next]))

    return []


n = int(read())

result = solution(n)
print(len(result)-1)
print(' '.join(list(map(str, result))))
