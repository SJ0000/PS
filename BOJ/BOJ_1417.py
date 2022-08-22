
from collections import deque

import sys


def read():
    return sys.stdin.readline().rstrip()


N = int(read())

votes = []
for _ in range(N):
    votes.append(int(read()))

count = 0
while True:
    candidate = -1
    max_vote = -1
    for i in range(N):
        if votes[i] >= max_vote:
            candidate = i
            max_vote = votes[i]
    if candidate == 0:
        break
    count += 1
    votes[0] += 1
    votes[candidate] -= 1

print(count)
