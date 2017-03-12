#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def median(nums1, nums2):
    nums = nums1+nums2
    nums.sort()
    l = len(nums)
    return nums[(l-1)/2]

while True:
    try:
        nums1 = map(int, raw_input().split())
        nums1.pop(0)
        nums2 = map(int, raw_input().split())
        nums2.pop(0)
        print median(nums1, nums2)
    except:
        break
