

import sys


def read():
    return sys.stdin.readline().rstrip()


def process(height):
    global a, B
    removed = 0
    required = 0
    for row in a:
        for h in row:
            if h < height:
                required += height - h
            if h > height:
                removed += h - height
    # 불가능일때 -1, 가능하면 시간을 return
    time = (removed*2) + required
    return time if (B+removed) >= required else -1


N, M, B = map(int, read().split())

a = []
min_height = 256
max_height = 0
for _ in range(N):
    a.append(list(map(int, read().split())))

for row in a:
    row_min = min(row)
    row_max = max(row)
    min_height = min(min_height, row_min)
    max_height = max(max_height, row_max)

result = []
for height in range(min_height, max_height+1):
    time = process(height)
    if time != -1:
        result.append((time, -height))

result.sort()
print(result[0][0], -result[0][1])
