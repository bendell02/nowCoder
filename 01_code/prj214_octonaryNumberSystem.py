#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def octonaryNumber(num):
    rlt = ''
    while num:
        temp = num % 8
        num = num / 8
        rlt = str(temp) + rlt
    return rlt

while True:
    try:
        num = input()
        rlt = octonaryNumber(num)
        print rlt
    except:
        break
