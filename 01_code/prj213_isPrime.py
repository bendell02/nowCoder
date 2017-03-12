#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

import math
def isPrime(number):
    if number > 1:
        if number == 2:
            return True
        if number % 2 == 0:
            return False
        for current in range(3, int(math.sqrt(number) + 1), 2):
            if number % current == 0:
                return False
        return True
    return False

while True:
    try:
        num = input()
        if isPrime(num):
            print 'yes'
        else:
            print 'no'
    except:
        break
