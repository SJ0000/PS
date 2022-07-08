
import sys


def read():
    return sys.stdin.readline().rstrip()


# 예제 3번을 보고 연결된 체인을 single로 변경하는게 가능하다는 것을 떠올림
N = int(read())
chains = list(map(int, read().split()))

# 길이1인 체인과 1보다 긴 체인을 분리
single = len(list(filter(lambda x: x == 1, chains)))
long_chains = list(filter(lambda x: x != 1, chains))
answer = 0

# single을 long chain 사이에 연결
# 1) single이 충분한 경우
# 2) single이 모자란 경우
if single >= len(long_chains)-1:
    answer += len(long_chains)-1
    single -= len(long_chains)-1
    # single chain + 하나로 합쳐진 long chain 만 남음
    answer += (single+1)//2
else:
    # long chain 에서 필요한 만큼 single chain으로 분리
    long_chains.sort()
    single_required = (len(long_chains)-1)-single
    remain_long_chains = len(long_chains)
    for long in long_chains:
        if single_required >= long:
            single_required -= long
            single += long
            # long chain 하나가 사라졌기 때문에 필요한 single 갯수도 하나 줄어든다.
            single_required -= 1
            remain_long_chains -= 1
            if single_required <= 0:
                break
        else:
            single += single_required
            single_required = 0
            break
    answer += single

print(answer)
