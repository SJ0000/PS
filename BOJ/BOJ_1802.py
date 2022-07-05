
def fold(s):
    li = list(map(int, list(s)))
    reversed = list(map(lambda x: str((x+1) % 2), li))
    reversed.reverse()
    return ''.join(reversed)


def can_fold(paper):
    if len(paper) == 1:
        return True
    mid = len(paper)//2
    x = paper[:mid]
    y = fold(paper[mid+1:])
    if x == y:
        return can_fold(x)
    return False


T = int(input())

for _ in range(T):
    paper = input()
    if can_fold(paper):
        print("YES")
    else:
        print("NO")
