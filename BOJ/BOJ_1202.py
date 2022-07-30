

import heapq
import sys


def read():
    return sys.stdin.readline().rstrip()


N, K = map(int, read().split())
info = []  # 값, 무게
bag = []

for _ in range(N):
    m, v = map(int, read().split())
    info.append((m, v))

for _ in range(K):
    bag.append(int(read()))

info.sort()
bag.sort()

hq = list()

total_price = 0
info_index = 0
for i in range(K):
    capa = bag[i]
    while info_index < N:
        weight, price = info[info_index]
        if weight <= capa:
            heapq.heappush(hq, -price)
            info_index += 1
        else:
            break
    if len(hq) > 0:
        selected = -heapq.heappop(hq)
        total_price += selected

print(total_price)
