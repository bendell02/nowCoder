#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def mycmp(a, b):
    l1 = len(a); l2 = len(b)
    return cmp(l1, l2)

while True:
    try:
        N = input()
        sList = []
        while N:
            N -= 1
            line = raw_input()
            if line == "stop":
                break
            sList.append(line)
        sList.sort(mycmp)
        for line in sList:
            print line
    except:
        break
