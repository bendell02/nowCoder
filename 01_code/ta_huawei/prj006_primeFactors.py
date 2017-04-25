#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

import sys

def getResult(num):
    i = 2; result = ''
    if num > 1:
        while i*i < num:
            while num%i == 0:
                result += str(i) + ' '
                num /= i
            i += 1
        if 1 != num:
            result += str(num) + ' '
    print result

while True:
    try:
        num = sys.stdin.readline()
        num = int(num)
        getResult(num)
    except:
        break
