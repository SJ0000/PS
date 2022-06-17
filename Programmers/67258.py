
def solution(gems):

    gem_dict = dict()
    index = 0
    for gem in gems:
        if gem_dict.get(gem) == None:
            gem_dict[gem] = index
            index += 1
    gems = list(map(lambda g: gem_dict[g], gems))
    n = len(gem_dict)
    answer = [1, len(gems)]

    l = 0
    r = 0

    gem_count = dict()
    for i in range(n):
        gem_count[i] = 0

    gem_set = set()

    def has_all_gems():
        return len(gem_set) == n

    def add_gem(item):
        gem_set.add(item)
        gem_count[item] += 1

    def remove_gem(item):
        gem_count[item] -= 1
        if gem_count[item] == 0:
            gem_set.remove(item)

    add_gem(0)

    while r < len(gems):

        if has_all_gems():
            if answer[1]-answer[0] > r-l:
                answer = [l+1, r+1]
                if r-l+1 == n:
                    break

        r += 1
        if r == len(gems):
            break

        add_gem(gems[r])

        while l <= r:
            gem = gems[l]
            remove_gem(gem)
            if gem_count[gem] > 0:
                l += 1
            else:
                add_gem(gem)
                break

    return answer


print(solution(["DIA", "RUBY", "RUBY", "DIA",
      "DIA", "EMERALD", "SAPPHIRE", "DIA"]))

print(solution(["AA", "AB", "AC", "AA", "AC"]))

print(solution(["XYZ", "XYZ", "XYZ"]))

print(solution(["ZZZ", "YYY", "NNNN", "YYY", "BBB"]))
