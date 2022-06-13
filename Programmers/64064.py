
answer_set = set()


def is_possible(uid, bid):
    if len(uid) != len(bid):
        return False

    for (a, b) in zip(uid, bid):
        if b == '*':
            continue
        if a != b:
            return False
    return True


def search(targets, index, selected):
    global count
    if index == len(targets):
        answer_set.add(tuple(sorted(list(selected))))
        # print(selected)
        return

    for target in targets[index]:
        if target in selected:
            continue
        selected.add(target)
        search(targets, index+1, selected)
        selected.remove(target)


def solution(user_id, banned_id):
    global answer_set
    targets = []
    for bid in banned_id:
        target = []
        for (index, uid) in enumerate(user_id):
            if is_possible(uid, bid):
                target.append(index)
        targets.append(target)

    # print("targets = ", targets)
    search(targets, 0, set())
    # print(answer_set)
    return len(answer_set)


print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],
      ["fr*d*", "*rodo", "******", "******"]))
