#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def whichTriangle(numList):
    numList.sort()
    tmpLong = numList[2]*numList[2]
    tempShorts = numList[1]*numList[1]+numList[0]*numList[0]
    if tempShorts > tmpLong:
        print '锐角三角形'
    elif tempShorts == tmpLong:
        print '直角三角形'
    else:
        print '钝角三角形'

while True:
    try:
        numList = map(int, raw_input().split())
        whichTriangle(numList)
    except:
        break
