
import sys


def read():
    return sys.stdin.readline().rstrip()


def solve():
    n = int(read())
    types = dict()
    for _ in range(n):
        (item, item_type) = read().split()
        if types.get(item_type) == None:
            types[item_type] = 1
        else:
            types[item_type] += 1

    answer = 1
    for key in types.keys():
        answer *= (types[key]+1)
    print(answer-1)


TC = int(read())
for _ in range(TC):
    solve()
