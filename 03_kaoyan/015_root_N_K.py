def root(x, y, k):
    rlt = 1
    while y:
        if y&1 == 1:
            rlt = (rlt*x)%k
        x = (x*x)%k
        y = y>>1
    rlt = rlt if rlt else k
    return rlt

while True:
    try:
        x, y, k = map(int, raw_input().strip().split())
        print root(x, y, k-1)
    except:
        break
