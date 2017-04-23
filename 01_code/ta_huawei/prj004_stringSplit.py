#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def stringSplit(oldStr):
    l = len(oldStr)
    groups = (l/8+1) if (l%8) else (l/8)
    newStr = oldStr + ('0'*(8*groups-l))
    for idx in range(groups):
        start = 8*idx
        end = 8*(idx+1)
        print newStr[start:end]

while True:
    try:
        stringSplit(raw_input())
    except:
        break
