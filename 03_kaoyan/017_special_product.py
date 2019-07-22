while True:
    try:
        m, n = raw_input().strip().split()
        m = map(int, m)
        n = map(int, n)
        rlt = 0
        for i in m:
            for j in n:
                rlt += i*j
        print rlt
    except:
        break 
