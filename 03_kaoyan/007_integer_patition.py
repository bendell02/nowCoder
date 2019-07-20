rlt = [1]*1000001; i = 1
while i<500000:
    rlt[2*i+1] = rlt[2*i] = (rlt[2*i-2] + rlt[i])%1000000000
    i += 1

while True:
    try:
        N = input()
        print rlt[N]
    except:
        break
