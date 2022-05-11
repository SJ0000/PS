
def solution(s):

    def convert(binary):
        zero_removed = binary.replace('0', '')
        converted = bin(len(zero_removed))[2:]
        return [converted, len(binary)-len(zero_removed)]

    zero_count = 0
    loop_count = 0
    while True:
        if s == '1':
            break
        loop_count += 1
        [s, removed] = convert(s)
        zero_count += removed

    return [loop_count, zero_count]


print(solution('110010101001'))
