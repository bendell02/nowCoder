#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def countOne(num):
    result = 0
    while (num>0):
        result += 1
        num &= (num-1)
    return result

num = int(raw_input())
print countOne(num)
