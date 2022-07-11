

import sys


def read():
    return sys.stdin.readline().rstrip()


def get_diff(i):
    global psum, N
    if i == 0:
        return psum[N-1]-psum[0]
    if i == N-1:
        return psum[N-2]
    return abs(psum[i-1] - (psum[N-1] - psum[i]))


N = int(read())

info = []
for _ in range(N):
    pos, value = map(int, read().split())
    info.append((pos, value))

info.sort()

psum = [0 for _ in range(N)]
psum[0] = info[0][1]
for i in range(1, N):
    psum[i] = psum[i-1] + info[i][1]

if N == 1:
    print(info[0][0])
elif N == 2:
    diff0 = get_diff(0)
    diff1 = get_diff(1)
    if diff0 > diff1:
        print(info[1][0])
    else:
        print(info[0][0])
else:
    prev_diff = get_diff(0)
    answer = N-1
    for i in range(1, N):
        diff = get_diff(i)
        if prev_diff <= diff:
            answer = i-1
            break
        prev_diff = diff
    print(info[answer][0])
