#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

while True:
    try:
        N = input()
        x, y, z = map(int, raw_input().strip().split())
        tempSum = x*1000+y*100+z*10
        isFind = False
        for a in range(9, 0, -1):
            for b in range(9, -1, -1):
                tempPartSum = a*10000+b
                if (tempSum+tempPartSum)%N == 0:
                    isFind = True
                    break
            if isFind:
                break
        if isFind:
            print a, b, (tempSum+tempPartSum)/N
        else:
            print '0'
    except:
        break

