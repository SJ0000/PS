
from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


def read_input():
    h, w = map(int, read().split())
    a = []
    line = []
    for _ in range(w+2):
        line.append('.')
    a.append(line)
    for _ in range(h):
        a.append(list('.' + read() + '.'))
    a.append(line)
    keys = read()
    if keys == '0':
        return (a, '')
    return (a, keys)


def solution():
    result = 0
    (a, key) = read_input()
    n, m = len(a), len(a[0])
    visit = [[False for _ in range(m)] for _ in range(n)]
    moves = [(0, 1), (1, 0), (-1, 0), (0, -1)]

    def visit_clear():
        for i in range(len(visit)):
            for j in range(len(visit[0])):
                visit[i][j] = False

    def open(ch):
        for i in range(len(a)):
            for j in range(len(a[0])):
                if a[i][j] == ch or a[i][j] == ch.upper():
                    a[i][j] = '.'

    for ch in key:
        open(ch)

    visit[0][0] = True
    q = deque()
    q.append((0, 0))
    while len(q) > 0:
        (x, y) = q.popleft()
        for (dx, dy) in moves:
            ax, ay = x+dx, y+dy
            if not (0 <= ax < n and 0 <= ay < m):
                continue
            if visit[ax][ay]:
                continue
            if a[ax][ay] == '*':
                continue
            if 'A' <= a[ax][ay] <= 'Z':
                continue
            if 'a' <= a[ax][ay] <= 'z':
                open(a[ax][ay])
                visit_clear()
            if a[ax][ay] == '$':
                result += 1
                a[ax][ay] = '.'

            visit[ax][ay] = True
            q.append((ax, ay))

    return result


TC = int(read())
for _ in range(TC):
    print(solution())
    #print("answer", solution())
