
max_score = -987654321
max_shot_info = []


def process(ryan, apeach):
    global max_score
    global max_shot_info

    r_score = 0
    a_score = 0
    for i in range(11):
        if ryan[i] == 0 and apeach[i] == 0:
            continue

        if ryan[i] > apeach[i]:
            r_score += 10-i
        else:
            a_score += 10-i

    diff = r_score - a_score
    if diff > max_score:
        max_score = diff
        max_shot_info = ryan
        return

    if diff == max_score:
        max_shot_info = get_higher_priority(ryan, max_shot_info)

# 낮은점수에 많이 쏜 경우를 return


def get_higher_priority(arr1, arr2):
    for i in range(10, -1, -1):
        if arr1[i] > arr2[i]:
            return arr1
        if arr1[i] < arr2[i]:
            return arr2

# 얻는 경우와 안얻는 경우


def search(index, remain_arrows, ryan, apeach):
    # base case
    copied = ryan[:]
    if index == 10:
        copied[10] += remain_arrows
        process(copied, apeach)
        return
    if remain_arrows == 0:
        process(copied, apeach)
        return

    # index번 점수 얻는 경우
    if remain_arrows > apeach[index]:
        copied[index] = apeach[index] + 1
        search(index+1, remain_arrows - copied[index], copied, apeach)

    # 점수 안 얻는 경우
    search(index+1, remain_arrows, ryan, apeach)


def solution(n, info):

    ryan = [0 for _ in range(11)]
    search(0, n, ryan, info)

    # print(max_score, max_shot_info)

    if max_score <= 0:
        return [-1]

    return max_shot_info


#print(solution(5, [2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0]))
#print(solution(1, [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]))
#print(solution(9, [0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1]))
print(solution(10, [0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3]))
