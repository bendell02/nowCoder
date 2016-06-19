#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def swapMinMax(nums):
    minNum = min(nums)
    minIdx = nums.index(minNum)
    maxNum = max(nums)
    maxIdx = nums.index(maxNum)
    nums[minIdx] = maxNum
    nums[maxIdx] = minNum
    return nums

while True:
    try:
        N = input()
        nums = map(int, raw_input().split())
        nums = swapMinMax(nums)
        numsStr = map(str, nums)
        print ' '.join(numsStr)
    except:
        break
