#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

import math

def getRlt(n, m):
    k=int(math.log(n*1.0/m, 2) + 1)
    temp = n - m*(2**(k-1)) + 1
    if temp > 2**(k-1):
        rlt = 2**k - 1
    else:
        rlt = 2**(k-1) - 1 + temp
    return rlt

while True:
    try:
        m, n = map(int, raw_input().strip().split())
        if n==0 and m==0:
            break
        print getRlt(n, m)
    except:
        break
