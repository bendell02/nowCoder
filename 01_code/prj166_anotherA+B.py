#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def mSystem(num, m):
    if num==0:
        return '0'
    rlt = ''
    while num:
        rlt = str(num%m) + rlt
        num /= m
    return rlt

while True:
    try:
        m, A, B = map(int, raw_input().strip().split())
        if m == 0:
            break
        print mSystem(A+B, m)
    except:
        break
