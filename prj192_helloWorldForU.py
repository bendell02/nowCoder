#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def printU(s):
    N = len(s)
    n1 = (N+2)/3
    n2 = (N+2)-2*n1
    rlt = [[' ' for col in range(n2)] for row in range(n1)]
    idx = 0
    for i in range(n1):
        rlt[i][0] = s[idx]
        idx += 1
    for i in range(1, n2):
        rlt[n1-1][i] = s[idx]
        idx += 1
    for i in range(1, n1):
        rlt[n1-1-i][n2-1] = s[idx]
        idx += 1
    for i in range(n1):
        print ''.join(rlt[i])

while True:
    try:
        s = raw_input()
        printU(s)
    except:
        break
