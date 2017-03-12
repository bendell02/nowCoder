#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def basicCompute(rlt, num, sym):
    rlt *= 1.0
    if sym == '+':
        rlt += num
    elif sym == '-':
        rlt -= num
    elif sym == '*':
        rlt *= num
    else:
        rlt /= num
    return rlt

def getList(s):
    l = len(s); start = end = 0
    numList = []; symList = []
    while end < l:
        if s[end].isdigit():
            end += 1
        else:
            num = int(s[start:end])
            numList.append(num)
            sym = s[end]
            symList.append(sym)
            start = end + 1; end += 1
    num = int(s[start:end])
    numList.append(num)
    return numList, symList

def computeExpression(s):
    numList, symList = getList(s)
    newSymList = []; idx = 0
    while symList:
        sym = symList.pop(0)
        if sym == '*' or sym == '/':
            num1 = numList.pop(idx)
            num2 = numList.pop(idx)
            midNum = basicCompute(num1, num2, sym)
            numList.insert(idx, midNum)
        else:
            newSymList.append(sym)
            idx += 1
    rlt = numList.pop(0)
    for sym in newSymList:
        num = numList.pop(0)
        rlt = basicCompute(rlt, num, sym)
    return rlt    

while True:
    try:
        s = raw_input()
        print int(computeExpression(s))
    except:
        break

