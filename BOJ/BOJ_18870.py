

import sys


def read():
    return sys.stdin.readline().rstrip()


N = int(read())
X = list(enumerate(map(int, read().split())))

X.sort(key=lambda x: x[1])

result = [0 for _ in range(N)]

count = 0
for i in range(1, N):
    prev_value = X[i-1][1]
    index, value = X[i]
    if value == prev_value:
        result[index] = count
    else:
        count += 1
        result[index] = count


print(" ".join(map(str, result)))
