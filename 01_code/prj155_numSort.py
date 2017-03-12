#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

while True:
    try:
        N = input()
        nums = map(int, raw_input().strip().split())
        numSet = set(nums)
        nums = list(numSet)
        nums.sort()
        nums = map(str, nums)
        print ' '.join(nums)
    except:
        break
