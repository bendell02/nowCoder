#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def howManySteps(num):
    rlt = 0
    while num != 1:
        if (num&1) == 1:
            num = (3*num+1)/2
        else:
            num /= 2
        rlt += 1
    return rlt

while True:
    try:
        num = input()
        if num == 0:
            break
        print howManySteps(num)
    except:
        break
