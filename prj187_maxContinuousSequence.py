#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def findMaxContinuousSequence(nums):
    maxSum = nums[0]
    startIdx = endIdx = -1
    maxSumSequence = nums[:]
    l = len(nums); idx = 1
    while idx < l:
        maxSumSequence[idx] = max(nums[idx], maxSumSequence[idx-1]+nums[idx])
        maxSum = max(maxSum, maxSumSequence[idx])
        idx += 1
    for idx, num in enumerate(maxSumSequence):
        if startIdx == -1 and num >= 0:
            startIdx = idx
        if num < 0:
            startIdx = -1
        if num == maxSum:
            endIdx = idx
            break
    if maxSum < 0:
        return 0, nums[0], nums[-1]
    else:
        return maxSum, nums[startIdx], nums[endIdx]

while True:
    try:
        N = input()
        if N == 0:
            break
        nums = map(int, raw_input().split())
        maxSum, first, end = findMaxContinuousSequence(nums)
        print maxSum, first, end
    except:
        break