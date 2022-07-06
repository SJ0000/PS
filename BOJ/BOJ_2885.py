
import sys


def read():
    return sys.stdin.readline().rstrip()


def solution(k):
    n = 0
    while 2**n < k:
        n += 1
    if 2**n == k:
        print(k, 0)
        return

    binary = bin(k)[2:]
    print(binary)
    last_one_index = -1
    for i in range(len(binary)-1, -1, -1):
        if binary[i] == '1':
            last_one_index = i
            break
    print(2**n, last_one_index+1)


K = int(read())
solution(K)
