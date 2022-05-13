def solution(s):

    def to_jaden(x):
        if x == '':
            return x

        jaden = x.lower()
        if x[0].isalpha() == False:
            return jaden

        return jaden[0].upper() + jaden[1:]

    li = list(map(to_jaden, s.split(' ')))

    return ' '.join(li)


print(solution("A aa aa 1aA aaa bxddfe   Aaa  2aaA  A "))
