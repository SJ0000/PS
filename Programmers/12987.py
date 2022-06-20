def solution(A, B):
    n = len(A)
    A.sort()
    B.sort()

    i = 0
    j = 0
    wins = 0
    while j < n:
        if A[i] < B[j]:
            wins += 1
        else:
            j += 1
            continue
        i += 1
        j += 1

    return wins


print(solution([2, 2, 2, 2], [1, 1, 1, 1]))
