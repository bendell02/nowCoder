#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def isPerfectNum(N):
    facs = []
    for i in range(1, N):
        if N%i == 0:
            facs.append(i)
    if N == sum(facs):
        return True
    else:
        return False

while True:
    try:
        N = input()
        rlt = []
        for i in range(1, N+1):
            if isPerfectNum(i):
                rlt.append(i)
        rlt = map(str, rlt)
        print ' '.join(rlt)
    except:
        break
