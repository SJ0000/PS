
puddles = []
N, L = map(int, input().split())
for _ in range(N):
    x, y = map(int, input().split())
    if x < y:
        puddles.append((x, y))
    else:
        puddles.append((y, x))

puddles.sort()
answer = 0
covered = -1
for (x, y) in puddles:
    # 아예 새로 덮어야 하는 경우
    if x >= covered:
        dist = y-x
        required = dist//L if dist % L == 0 else (dist//L)+1
        answer += required
        covered = x+(required*L)

    # 일부분이 덮인 경우
    else:
        dist = y-covered
        required = dist//L if dist % L == 0 else (dist//L)+1
        answer += required
        covered = covered+(required*L)

    #print("covered", covered)

print(answer)
