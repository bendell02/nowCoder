#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def sameK(A, B, K):
    base = 10**K
    if A%base == B%base:
        return True
    else:
        return False

while True:
    try:
        A, B, K = map(int, raw_input().strip().split())
        if A==0 and B==0:
            break
        if sameK(A, B, K):
            print '-1'
        else:
            print (A+B)
    except:
        break
