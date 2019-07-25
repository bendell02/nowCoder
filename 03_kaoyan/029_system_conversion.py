def readCh(ch):
    if ch.isupper():
        return (ord(ch)-55)
    else:
        return (ord(ch)-48)

def outputCh(num):
    if num>9:
        return chr(num+87)
    else:
        return chr(num+48)

def readMSys(numStr, base):
    idx = len(numStr)-1
    rlt = 0; mul = 1
    while idx >= 0:
        rlt += (mul * readCh(numStr[idx]))
        idx -= 1
        mul *= base
    return rlt

def conversion(num, N):
    rlt = ''
    while num > 0:
        rlt = outputCh(num%N) + rlt
        num /= N
    return rlt

while True:
    try:
        M, N = map(int, raw_input().strip().split())
        numStr = raw_input().strip()
        print conversion(readMSys(numStr, M), N)
    except:
        break
