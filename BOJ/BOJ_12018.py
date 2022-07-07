
import sys


def read():
    return sys.stdin.readline().rstrip()


n, m = map(int, read().split())
needs = []
for _ in range(n):
    p, l = map(int, read().split())
    mileages = list(map(int, read().split()))

    if p < l:
        needs.append(1)
        continue

    mileages.sort(reverse=True)
    needs.append(mileages[l-1])

needs.sort()
count = 0
used_mileage = 0
for need in needs:
    if used_mileage + need > m:
        break
    used_mileage += need
    count += 1

print(count)
