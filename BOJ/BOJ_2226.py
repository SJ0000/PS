n = int(input())
d = list(range(1000))
d[0] = 0
d[1] = 1
for i in range(2,10):
    d[i] = d[i-1]*2
    if i%2 == 0:
        d[i] = d[i]-1
    else:
        d[i] = d[i]+1
print(d[n-1])