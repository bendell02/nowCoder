#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

maxN = 11
factorials = [1]*maxN
for i in range(1, maxN):
    factorials[i] = i*factorials[i-1]

def isValid(num):
    idx = maxN-1
    while idx>=0:
        if num >= factorials[idx]:
            num -= factorials[idx]
        idx -=1
    if num==0:
        return True
    else:
        return False

while True:
    try:
        N = input()
        if isValid(N):
            print "YES"
        else:
            print "NO"
    except:
        break
