

def solution(dirs):

    def can_visit(pos):
        (x, y) = pos
        return -5 <= x <= 5 and -5 <= y <= 5

    def next(pos, command):
        (x, y) = pos
        if command == 'U':
            return (x-1, y)
        if command == 'D':
            return (x+1, y)
        if command == 'L':
            return (x, y-1)
        if command == 'R':
            return (x, y+1)
        return pos

    current_pos = (0, 0)
    routes = set()

    for dir in dirs:
        next_pos = next(current_pos, dir)
        if can_visit(next_pos):
            routes.add((current_pos, next_pos))
            routes.add((next_pos, current_pos))
            current_pos = next_pos

    return len(routes)//2


print(solution("LULLLLLLU"))
