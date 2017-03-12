#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

stickLength = 100
while True:
    try:
        N = input()
        postions = [0]*N
        speeds = [0]*N
        numLeft = numRight = posA = 0
        leftValidAnts = []
        rightValidAnts = []

        for i in range(N):
            p, d = map(int, raw_input().strip().split())
            postions[i] = p
            speeds[i] = d
            if d == 0:
                posA = p

        for i in range(N):
            if postions[i]<posA and speeds[i]>0:
                leftValidAnts.append(stickLength-postions[i])
                numLeft += 1
            elif postions[i]>posA and speeds[i]<0:
                rightValidAnts.append(postions[i])
                numRight += 1

        if numLeft == numRight:
            print "Cannot fall!"
        elif numLeft > numRight:
            leftValidAnts.sort()
            print leftValidAnts[numRight]
        else:
            rightValidAnts.sort()
            print rightValidAnts[numLeft]
    except:
        break
