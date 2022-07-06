
from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()

# 팔아야 할 시점 계산


def get_sell_time(chart):
    time = deque()
    start = 0
    while start < len(chart):
        high = max(chart[start:])
        for i in range(len(chart)-1, -1, -1):
            if chart[i] == high:
                time.append(i)
                start = i+1
                break

        while start < len(chart)-1 and chart[start] > chart[start+1]:
            start += 1
    return time


def solution(chart):
    sell = get_sell_time(chart)
    stock = 0
    expense = 0  # 지출
    profit = 0  # 수입

    for i in range(len(chart)):
        price = chart[i]
        # 팔아야 할 때
        if i == sell[0]:
            profit += stock*price
            stock = 0
            sell.popleft()
            if len(sell) == 0:
                break
            continue
        # 사야 할 때
        if price < chart[sell[0]]:
            expense += price
            stock += 1

    return profit-expense


T = int(read())

for _ in range(T):
    N = int(read())
    chart = list(map(int, read().split()))
    print(solution(chart))
