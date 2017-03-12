#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

while True:
    try:
        n, m = map(int, raw_input().strip().split())
        if m==0 and n==0:
            break
        money = map(int, raw_input().strip().split())
        money.sort(reverse=True)
        if m>n:
            m = n
        rlt = money[:m]; rlt = map(str, rlt)
        print ' '.join(rlt)
    except:
        break

