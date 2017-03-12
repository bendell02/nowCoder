#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def findX(nums, x):
    try:
        idx = nums.index(x)
    except:
        idx = -1
    return idx

while True:
    try:
        N = input()
        nums = map(int, raw_input().split())
        x = input()
        print findX(nums, x)
    except:
        break
