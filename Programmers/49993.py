def solution(skill, skill_trees):

    skill_dict = dict()
    for (index, s) in enumerate(list(skill)):
        skill_dict[s] = index

    def is_possible(skill_tree):
        skills = list(skill_tree)
        learn_index = 0
        for x in skills:
            print(learn_index, x)
            if skill_dict.get(x) == None:
                continue

            if learn_index < skill_dict[x]:
                return False

            learn_index += 1

        return True

    answer = list(filter(is_possible, skill_trees))
    print(answer)

    return len(answer)


print(solution("CBD", ["BACDE", "CBADF", "AECB", "BDA"]))
