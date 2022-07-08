

import sys


def read():
    return sys.stdin.readline().rstrip()


def switch(a, i):
    n = len(a)
    if i == 0:
        a[i] = (a[i]+1) % 2
        a[i+1] = (a[i+1]+1) % 2
        return
    if i == n-1:
        a[i-1] = (a[i-1]+1) % 2
        a[i] = (a[i]+1) % 2
        return
    a[i-1] = (a[i-1]+1) % 2
    a[i] = (a[i]+1) % 2
    a[i+1] = (a[i+1]+1) % 2


def process(a):
    global want
    a_count = 0
    i = 1
    while i < N:
        if i < N-1 and a[i-1] != want[i-1] and a[i] != want[i] and a[i+1] != want[i+1]:
            switch(a, i)
            a_count += 1
            i += 2
            continue
        if a[i-1] != want[i-1]:
            switch(a, i)
            a_count += 1
        i += 1
    return a_count if a == want else -1


N = int(read())
origin = list(map(int, list(read())))
want = list(map(int, list(read())))

result1 = process(origin[:])

first_switched = origin[:]
switch(first_switched, 0)
result2 = process(first_switched)


if result1 != -1 and result2 != -1:
    print(min(result1, result2+1))
elif result1 != -1:
    print(result1)
elif result2 != -1:
    print(result2+1)
else:
    print(-1)
