#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

numRange = 11

def getCommonNum(nums):
    freq = [0]*numRange
    for num in nums:
        freq[num] += 1
    maxFreq = max(freq)
    return freq.index(maxFreq)

while True:
    try:
        nums = map(int, raw_input().split())
        if not nums:
            break
        print getCommonNum(nums)
    except:
        break
