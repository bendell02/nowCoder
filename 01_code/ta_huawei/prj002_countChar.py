#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

while True:
    try:
        oriStr = raw_input()
        ch = raw_input()
        oriStr = oriStr.lower()
        ch = ch.lower()
        count = 0
        for sc in oriStr:
            if sc == ch:
                count += 1
        print count
    except:
        break
