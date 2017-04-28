#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

import sys

numStr = sys.stdin.readline()
numStr = numStr[::-1]
newStr = ''
for ch in numStr:
    if ch not in newStr and ch != '\n':
        newStr = newStr + ch
print newStr
