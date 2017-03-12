#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

import math

def y1y2(n, idx):
    rlt = 0
    while idx <= n:
        rlt += math.factorial(idx)
        idx += 2
    return rlt

while True:
    try:
        n = input()
        print y1y2(n, 1), y1y2(n, 2)
    except:
        break
