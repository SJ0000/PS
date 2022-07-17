
from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


N, M = map(int, read().split())
passwords = dict()
for _ in range(N):
    address, password = read().split()
    passwords[address] = password

for _ in range(M):
    address = read()
    print(passwords[address])
