E = []; G = []
def judge(num):
    rlt = 0
    for i in range(1, num):
        if num%i == 0:
            rlt += i
    if rlt > num:
        G.append(num)
    elif rlt == num:
        E.append(num)

for num in range(2, 61):
    judge(num)
E = map(str, E); G = map(str, G)
print('E: '+' '.join(E))
print('G: '+' '.join(G))
