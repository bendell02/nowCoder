#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def isMatch(s, p , j, m):
    for i in range(m):
        if s[j+i] != p[i]:
            return False
    return True

def howManyShifts(s, p):
    m = len(p); l = len(s)-m
    rlt = 0
    for j in range(l+1):
        if isMatch(s, p, j, m):
            rlt += 1
    return rlt

while True:
    try:
        s, p = raw_input().strip().split()
        print howManyShifts(s, p)
    except:
        break
