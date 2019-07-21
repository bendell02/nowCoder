def solveStr(string):
    strList = list(string)
    rlt = 0
    idx = strList.index('2')
    rlt += (idx - 0)
    strList.insert(0, strList.pop(idx))
    idx = strList.index('0', 1)
    rlt += (idx - 1)
    strList.insert(1, strList.pop(idx))
    idx = strList.index('1', 2)
    rlt += (idx - 2)
    strList.insert(2, strList.pop(idx))
    idx = strList.index('2', 3)
    rlt += (idx - 3)
    return rlt

while True:
    try:
        N = input()
        string = raw_input()
        steps = -1; start = end = 0; num = 0
        sd = {'2':0, '0':0, '1':0}
        while end < N:
            ch = string[end]
            if sd[ch]==0 or (ch=='2' and sd[ch]==1):
                num += 1
            sd[ch] += 1
            while num == 4:
                tempStep = solveStr(string[start:end+1])
                if steps==-1 or tempStep<steps:
                    steps = tempStep
                ch = string[start]
                sd[ch] -= 1
                if sd[ch]==0 or (ch=='2' and sd[ch]==1):
                    num -= 1
                start += 1
            end += 1
        print steps
    except:
        break
