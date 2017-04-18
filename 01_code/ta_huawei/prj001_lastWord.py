#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

while True:
    try:
        oriStr = raw_input()
        strList = oriStr.split()
        print len(strList[-1])
    except:
        break
