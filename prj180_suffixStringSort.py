#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

while True:
    try:
        s = raw_input()
        l = len(s); sList = []
        for i in range(l):
            sList.append(s[i:])
        sList.sort()
        for chs in sList:
            print chs
    except:
        break
