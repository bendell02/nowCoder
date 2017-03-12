#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

import bisect

def getPos(rlt, num):
    idx = 0
    while rlt[idx]<num:
        idx += 1
    return idx

def LIS(nums):
    rlt = []; l = len(nums)
    up = [1] * l
    for idx,num in enumerate(nums):
        if (not rlt) or num>rlt[-1]:
            rlt.append(num)
            up[idx] = len(rlt)
        else:
            #pos = bisect.bisect_left(rlt, num)
            pos = getPos(rlt, num)
            rlt[pos] = num
            up[idx] = pos+1
    return up

while True:
    try:
        N = input()
        nums = map(int, raw_input().split())
        up = LIS(nums); nums.reverse()
        down = LIS(nums); down.reverse()
        rlt = 1
        for i in range(N):
            temp = up[i]+down[i]-1
            rlt = max(rlt, temp)
        print (N-rlt)
    except:
        break
