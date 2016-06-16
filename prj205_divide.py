#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

import math

def divideInt(n, a):
    k = 0
    while n%(a**k)==0:
        k += 1
    return k-1

while True:
    try:
        n, a = map(int, raw_input().split())
        print divideInt(math.factorial(n), a)
    except:
        break
