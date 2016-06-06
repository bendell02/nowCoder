#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

while True:
    try:
        n = input()
        for x in range(0, (3*n-100)/14+1):
            for y in range(0, (3*n-100-14*x)/8+1):
                z = 100 - x - y
                print "x=%d,y=%d,z=%d" % (x, y, z)
    except:
        break
