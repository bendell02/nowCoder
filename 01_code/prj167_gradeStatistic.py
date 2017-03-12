#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

while True:
    try:
        N = input()
        if N == 0:
            break
        grades = map(int, raw_input().strip().split())
        request = input()
        gradesFreq = [0]*101
        for grade in grades:
            gradesFreq[grade] += 1
        print gradesFreq[request]
    except:
        break
