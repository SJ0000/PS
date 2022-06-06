def solution(fees, records):
    [basic_minutes, basic_fee, unit_minutes, unit_fee] = list(map(int, fees))

    parking_lot = dict()
    car_in_minutes = dict()

    def calculate_fee(minutes):
        if minutes <= basic_minutes:
            return basic_fee

        unit = 0
        if (minutes-basic_minutes) % unit_minutes == 0:
            unit = (minutes-basic_minutes)//unit_minutes
        else:
            unit = ((minutes-basic_minutes)//unit_minutes)+1

        return basic_fee + unit * unit_fee

    def time_to_minutes(time):
        [hour, minutes] = list(map(int, time.split(":")))
        return hour*60 + minutes

    def process(record):
        print(record)
        [time, car_number, status] = record.split(" ")
        minutes = time_to_minutes(time)
        if status == "IN":
            in_process(car_number, minutes)
        else:
            out_process(car_number, minutes)

    def in_process(car_number, in_minutes):
        parking_lot[car_number] = in_minutes

    def out_process(car_number, out_minutes):
        in_minutes = parking_lot[car_number]
        diff = out_minutes - in_minutes
        if car_in_minutes.get(car_number) == None:
            car_in_minutes[car_number] = diff
        else:
            car_in_minutes[car_number] += diff
        parking_lot.pop(car_number)

    for record in records:
        process(record)

    last_time = time_to_minutes("23:59")
    for car in list(parking_lot.keys()):
        print("23:59", car, "OUT")
        out_process(car, last_time)

    answer = []
    for car in list(car_in_minutes.keys()):
        total_minutes = car_in_minutes[car]
        total_price = calculate_fee(total_minutes)
        answer.append((car, total_price))

    answer = sorted(answer)
    return list(map(lambda x: x[1], answer))


fees = [180, 5000, 10, 600]
records = ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT",
           "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]

print(solution(fees, records))
