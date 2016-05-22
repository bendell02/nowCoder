#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

N = input()
for n in range(N):
    unlocker = locker = ''
    minTime = '23:59:59'; maxTime = '00:00:00'
    M = input()
    for m in range(M):
        ID, checkIn, checkOut = raw_input().strip().split()
        if checkIn <= minTime:
            minTime, unlocker = checkIn, ID
        if checkOut >= maxTime:
            maxTime, locker = checkOut, ID
    print unlocker, locker
