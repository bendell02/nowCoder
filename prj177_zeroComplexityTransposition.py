#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

while True:
    try:
        N = input()
        nums = map(int, raw_input().strip().split())
        nums = nums[::-1]
        nums = map(str, nums)
        print ' '.join(nums)
    except:
        break
