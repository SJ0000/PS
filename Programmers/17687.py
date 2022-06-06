def num_to_char(n):
    if n <= 9:
        return str(n)
    diff = n-10
    return str(chr(ord('A')+diff))

# 10진법 숫자 -> n진법 문자열


def dec_to_string(dec, n):
    if dec == 0:
        return "0"

    ret = []
    a = dec
    b = 0
    while a > 0:
        b = a % n
        a //= n
        ret.append(b)
    ret.reverse()
    ret = list(map(num_to_char, ret))
    return ''.join(ret)

# n진법, 미리 구할 숫자 t개, 총 m명 중 p번째


def solution(n, t, m, p):
    words = []

    # 총 문자 개수가 최소 t*m개 되도록 미리 만들어야 함
    created_count = 0
    create_num = 0
    while created_count < t*m:
        created = dec_to_string(create_num, n)
        words.append(created)
        created_count += len(created)
        create_num += 1

    answer = []
    count = 0
    for (i, ch) in enumerate(''.join(words)):
        if count == t:
            break
        if i % m == p-1:
            answer.append(ch)
            count += 1

    return ''.join(answer)


print(solution(16, 16, 2, 2))
