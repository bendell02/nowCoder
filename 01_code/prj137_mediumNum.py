#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def getMedium(firstNums, secNums, a, b, c, d):
    nums = firstNums[a-1:b] + secNums[c-1:d]
    idx = (len(nums)-1)/2
    return nums[idx]

N = input()
while N>0:
    N -= 1
    line = raw_input()
    firstNums = map(int, raw_input().strip().split())
    secNums = map(int, raw_input().strip().split())
    a, b = map(int, raw_input().strip().split())
    c, d = map(int, raw_input().strip().split())
    print getMedium(firstNums, secNums, a, b, c, d)
