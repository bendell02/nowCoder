def countPrimeNum(num):
    cnt = 0; i = 2
    if num > 1:
        while i*i < num:
            while num%i == 0:
                cnt += 1
                num /= i
            i += 1
        cnt += 1
    return cnt

while True:
    try:
        N = input()
        print countPrimeNum(N)
    except:
        break
