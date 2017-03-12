#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def xxxLaw(num, states):
    while num != 1:
        if (num&1) == 1:
            num = (3*num+1)/2
        else:
            num /= 2
        if states[num] == True:
            break
        else:
            states[num] = True

while True:
    try:
        N = input()
        if N == 0:
            break
        nums = map(int, raw_input().strip().split())
        rlt = []; states = [False]*30000
        for num in nums:
            xxxLaw(num, states)
        for num in nums:
            if states[num] == False:
                rlt.insert(0, num)
        rlt = map(str, rlt)
        print ' '.join(rlt)
    except:
        break
