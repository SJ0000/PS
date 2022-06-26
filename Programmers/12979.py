def solution(n, stations, w):

    def get_required_stations(n):
        result = 0
        coverage = (2*w)+1
        result += n//coverage
        result = result if n % coverage == 0 else result+1
        return result

    current = 1
    remains = []
    for station in stations:
        st = station - w
        ed = station + w
        if current < st:
            remains.append(st - current)
        current = ed+1

    if current <= n:
        remains.append(n+1-current)

    requires = list(map(get_required_stations, remains))
    return sum(requires)


print("answer", solution(16, [9], 2))
