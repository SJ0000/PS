
import sys


def read():
    return sys.stdin.readline().rstrip()


def similar_palendrome(s, head_remove):
    removed = False
    head = 0
    tail = len(s)-1
    while head <= tail:
        if s[head] == s[tail]:
            head += 1
            tail -= 1
        else:
            if removed == True:
                return 2
            removed = True
            if head_remove == True:
                head += 1
            else:
                tail -= 1
    result = 1 if removed else 0
    return result


T = int(read())

for _ in range(T):
    s = input()
    head_removed = similar_palendrome(s, True)
    tail_removed = similar_palendrome(s, False)
    if head_removed == 0:
        print(0)
    elif head_removed == 1 or tail_removed == 1:
        print(1)
    else:
        print(2)
