
from collections import deque
import sys


def read():
    return sys.stdin.readline().rstrip()


# 나보다 큰 것 중 가장 작은 것
def binary_search(arr, value):
    l = 0
    r = len(arr)-1
    index = -1
    while l <= r:
        mid = (l+r)//2
        if arr[mid] == value:
            return mid
        if arr[mid] < value:
            l = mid+1
        else:
            index = mid
            r = mid-1
    return index


N = int(read())
A = list(map(int, read().split()))

temp = []
index = [0 for _ in range(N)]

for i in range(N):
    value = A[i]
    if len(temp) == 0 or temp[-1] < value:
        temp.append(value)
        index[i] = len(temp)-1
    else:
        find_index = binary_search(temp, value)
        temp[find_index] = value
        index[i] = find_index

    #print("temp", temp)

lis = []
current = len(temp)-1
for i in range(N-1, -1, -1):
    if index[i] == current:
        lis.append(A[i])
        current -= 1

# print(temp)
# print(index)

lis.reverse()
print(len(lis))
print(' '.join(map(str, lis)))
