#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def setSort():
    numCount = int(raw_input())
    s = set()
    for i in range(numCount):
        s.add(int(raw_input()))
    l = list(s)
    l.sort()
    for num in l:
        print num

while True:
    try:
        setSort()
    except:
        break
