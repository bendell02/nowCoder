#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

#import bisect

def LISSum(nums):
    dp=nums[:]
    for i in range(len(nums)):
        for j in range(i):
            if nums[i] > nums[j]:
                dp[i] = max(dp[i], dp[j]+nums[i])
    return max(dp)

while True:
    try:
        N = input()
        nums = map(int, raw_input().strip().split())
        print LISSum(nums)
    except:
        break
