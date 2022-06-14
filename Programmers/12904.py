

def solution(s):
    n = len(s)
    p = [[-1 for _ in range(n)] for __ in range(n)]

    def is_palindrome(st, ed):
        if p[st][ed] != -1:
            return p[st][ed]

        if st == ed:
            p[st][ed] = 1
            return p[st][ed]

        if st + 1 == ed:
            p[st][ed] = 1 if s[st] == s[ed] else 0
            return p[st][ed]

        if st >= 1:
            if is_palindrome(st+1, ed-1) and s[st] == s[ed]:
                p[st][ed] = 1
                return p[st][ed]

        # 새로 생성된 palindrome인 경우
        sub = s[st:ed+1]
        for i in range(len(sub)//2):
            if sub[i] != sub[len(sub)-1-i]:
                p[st][ed] = 0
                return p[st][ed]
        p[st][ed] = 1
        return p[st][ed]

    answer = 0
    # 길이 순서대로 탐색하도록 변경
    for length in range(1, n+1):
        for st in range(n):
            ed = st+length-1
            if ed >= n:
                break
            p[st][ed] = is_palindrome(st, ed)
            if p[st][ed] == 1:
                answer = max(answer, ed-st+1)

    return answer


x = "a"*2500
print(solution(x))
