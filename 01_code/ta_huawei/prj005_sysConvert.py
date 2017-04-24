#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

import sys

while True:
    try:
        num = sys.stdin.readline()
        print int(num, 16)
    except:
        break
