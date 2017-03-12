#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

maxBits = 25

radix = [2, 3, 5, 7, 11,\
    13, 17, 19, 23, 29,\
    31, 37, 41, 43, 47,\
    53, 59, 61, 67, 71,\
    73, 79, 83, 89, 97]

weight = [0]*maxBits

def calWeight():
    weight[0] = 1
    for i in range(1, maxBits):
        weight[i] = weight[i-1]*radix[i-1]

def readMarsNum(numStr):
    numList = map(int, numStr.split(','))
    l = len(numList)
    rlt = 0
    for idx, num in enumerate(numList):
        rlt += weight[l-1-idx]*num
    return rlt

def writeMarsNum(num):
    rltList = []
    for i in range(maxBits-1, -1, -1):
        tempRlt = num/weight[i]
        num -= tempRlt*weight[i]
        if tempRlt or rltList:
            rltList.append(tempRlt)
    rltList = map(str, rltList)
    rlt = ','.join(rltList)
    return rlt

calWeight()

while True:
    try:
        A, B = raw_input().split()
        numA = readMarsNum(A)
        numB = readMarsNum(B)
        numSum = numA + numB
        if numSum == 0:
            break
        print writeMarsNum(numSum)
    except:
        break
