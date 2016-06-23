#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def reverseNum(num):
    rlt = str(num)
    rlt = rlt[::-1]
    return rlt

N = input()
while N:
    N -= 1
    num1, num2 = map(int, raw_input().strip().split())
    tempSum = num1 + num2
    reverseSum = reverseNum(tempSum)
    if reverseSum == str(int(reverseNum(num1))+int(reverseNum(num2))):
        print tempSum
    else:
        print "NO"
