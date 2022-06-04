# 각 기둥의 이름이 A,B,C 일때
# A개의 N개의 원반을 C로 이동하는 방법을 쪼개는 방법
# 1. A의 N-1개를 B(경유지)로 보낸다
# 2. A의 N을 C로 보낸다
# 3. B의 N-1개를 C로 보낸다.
def solution(n):
    answer = []

    def get_stopover(x, y):
        if x+y == 3:
            return 3
        if x+y == 4:
            return 2
        return 1

    def hanoi(fr, to, count):
        if count == 1:
            answer.append([fr, to])
            return

        stopover = get_stopover(fr, to)
        hanoi(fr, stopover, count-1)
        hanoi(fr, to, 1)
        hanoi(stopover, to, count-1)

    hanoi(1, 3, n)

    return answer


print(solution(4))
