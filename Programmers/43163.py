from collections import deque

word_set = set()
alphabet = 'abcdefghijklmnopqrstuvwxyz'


def get_candidates(word):
    # word에서 1글자 변경한 단어 중 word_set에 있는 단어들 반환

    candidates = []
    for (i, ch) in enumerate(word):
        for alpha in alphabet:
            if ch == alpha:
                continue
            created = word[:i] + alpha + word[i+1:]
            if created in word_set:
                candidates.append(created)

    return candidates


def solution(begin, target, words):

    visit = dict()
    q = deque()
    q.append(begin)

    for word in words:
        visit[word] = False
        word_set.add(word)

    completed = False
    count = 0
    while True:
        qs = len(q)
        for _ in range(qs):
            current = q.popleft()
            # print(count, current)
            if current == target:
                completed = True
                break
            visit[current] = True
            candidates = get_candidates(current)
            for candidate in candidates:
                if visit.get(candidate) == None:
                    continue
                if visit[candidate] == True:
                    continue
                q.append(candidate)
        if completed or len(q) == 0:
            break
        count += 1

    return count if completed else 0


print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]))
# print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log"]))
