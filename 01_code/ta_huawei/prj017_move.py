#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

import re

pattern = re.compile('[ADWS]\d{0,2}$')

def isValid(str):
    if pattern.match(str):
        return True
    else:
        return False

while True:
    try:
        orderList = raw_input().split(';')
        x = 0; y = 0
        for order in orderList:
            if isValid(order):
                data = int(order[1:])
                if 'A' == order[0]:
                    x -= data
                elif 'D' == order[0]:
                    x += data
                elif 'W' == order[0]:
                    y += data
                else:
                    y -= data
    
        print str(x)+','+str(y)
    except:
        break

