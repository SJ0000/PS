

import sys


def read():
    return sys.stdin.readline().rstrip()


def combination(n, r):
    global factorials
    return factorials[n]//(factorials[n-r]*factorials[r])


factorials = [1 for _ in range(101)]

for i in range(2, 101):
    factorials[i] = i*factorials[i-1]

n, m = map(int, read().split())

print(combination(n, m))
