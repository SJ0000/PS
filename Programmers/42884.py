
def solution(routes):

    routes.sort(key=lambda x: x[1])

    cameras = 0
    while len(routes) > 0:
        point = routes[0][1]
        routes = list(filter(lambda x: not x[0] <= point <= x[1], routes))
        cameras += 1

    return cameras


arr = [[-20, -15], [-14, -5], [-18, -13], [-5, -3]]
print(solution(arr))
