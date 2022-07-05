
x, y, w, s = map(int, input().split())

if x > y:
    x, y = y, x
# x < y
loadOnly = (x+y) * w
crossX = (x * s) + (y-x)*w
cross = (y*s) if (x+y) % 2 == 0 else ((y-1)*s) + w

print(min(loadOnly, crossX, cross))
