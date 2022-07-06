
import sys


def read():
    return sys.stdin.readline().rstrip()


def get_next_price(info, price):
    for (p, w) in info:
        if p > price:
            return p
    return -1


def solution(info, required):
    info.sort()
    max_price = 0
    count = 0
    total_weight = 0
    for (price, weight) in info:
        weight *= -1
        if total_weight >= required:
            break
        # 구매
        total_weight += weight
        if price == max_price:
            count += 1
        else:
            max_price = price
            count = 1

    if total_weight < required:
        print(-1)
        return

    # max_price보다 비싼 가격이 있는지 확인
    next_price = get_next_price(info, max_price)
    if next_price != -1 and next_price < max_price*count:
        print(next_price)
    else:
        print(max_price*count)


info = []
N, M = map(int, read().split())
for _ in range(N):
    weight, cost = map(int, read().split())
    info.append((cost, -weight))

solution(info, M)

# solution([(2, 1), (4, 2), (6, 3), (8, 4)], 9)
