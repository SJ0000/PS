def solution(arr):

    def gcd(a, b):
        if a < b:
            return gcd(b, a)
        n = a % b
        if n == 0:
            return b
        else:
            return gcd(b, n)

    def gcm(a, b):
        return (a*b)//gcd(a, b)

    answer = arr[0]
    for num in arr:
        answer = gcm(answer, num)

    return answer


print(solution([2, 6, 8, 14]))
