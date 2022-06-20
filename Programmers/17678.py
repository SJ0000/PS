
from collections import deque


def solution(n, t, m, timetable):
    answer = ''
    for time in range(0, to_minutes("23:59")+1):
        (possible, time) = simulation(n, t, m, timetable, time)
        if possible:
            answer = time

    return answer


def to_minutes(time):
    [hour, minutes] = time.split(":")
    return (int(hour) * 60) + int(minutes)


def to_time(minutes):
    hh = minutes//60
    hh_str = str(hh) if hh >= 10 else '0'+str(hh)
    mm = minutes % 60
    mm_str = str(mm) if mm >= 10 else '0'+str(mm)

    return hh_str+":"+mm_str


def simulation(n, t, m, timetable, con):

    shuttle = deque([to_minutes("09:00") + i*t for i in range(n)])
    without_con = sorted(
        list(map(lambda x: (to_minutes(x), False), timetable)))

    con_index = len(without_con)+1
    for (i, value) in enumerate(without_con):
        if value[0] > con:
            con_index = i
            break

    crews = deque(without_con[:con_index] +
                  [(con, True)] + without_con[con_index:])

    current = 0

    while current <= to_minutes("23:59"):
        if len(shuttle) == 0 or len(crews) == 0:
            break

        # 탑승 시간이 된 경우
        if current == shuttle[0]:
            for _ in range(min(len(crews), m)):
                if crews[0][0] <= current:
                    # 콘이 탑승한 경우
                    if crews[0][1]:
                        return (True, to_time(con))
                    crew = crews.popleft()
                    # print(to_time(current), crew, "in")

            shuttle.popleft()

        current += 1

    return (False, "xxxx")

#print(simulation(2, 10, 2, ["09:10", "09:09", "08:00"], to_minutes("09:10")))


print(solution(1, 1, 1, ["23:59"]))
