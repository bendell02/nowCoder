#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

while True:
    try:
        intStr,decStr = raw_input().split('.')
        intStr = int(intStr)
        decStr = int(decStr[0])
        if decStr >= 5:
            intStr += 1
        print intStr
    except:
        break
