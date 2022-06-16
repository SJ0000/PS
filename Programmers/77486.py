

def solution(enroll, referral, seller, amount):
    n = len(enroll)
    name_id = dict()
    name_id["-"] = -1
    profit = [0 for i in range(n)]
    for (id, name) in enumerate(enroll):
        name_id[name] = id
    referral = list(map(lambda name: name_id[name], referral))
    seller = list(map(lambda name: name_id[name], seller))
    amount = list(map(lambda x: x*100, amount))

    def get(i, money):
        if i == -1:
            return

        referral_money = money//10
        my_money = money-referral_money

        profit[i] += my_money
        if referral_money > 0:
            get(referral[i], referral_money)

    for (i, money) in zip(seller, amount):
        get(i, money)

    return profit


enroll = ["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"]
referral = ["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"]
seller = ["young", "john", "tod", "emily", "mary"]
amount = [12, 4, 2, 5, 10]

print(solution(enroll, referral, seller, amount))
result = [360, 958, 108, 0, 450, 18, 180, 1080]
