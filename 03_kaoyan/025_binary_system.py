def inverseNumber(num):
    numList = []
    while num:
        numList.append(num%2)
        num /= 2
    base = 1; rlt = 0
    while numList:
        rlt += (base*numList.pop())
        base *= 2
    return rlt

while True:
    try:
        num = input()
        print inverseNumber(num)
    except:
        break
