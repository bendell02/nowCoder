#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

import sys

while True:
    try:
        s = raw_input()
        if s == 'E':
            break
        zNum = oNum = jNum = 0
        for ch in s:
            if ch == 'Z':
                zNum += 1
            elif ch == 'O':
                oNum += 1
            elif ch == 'J':
                jNum += 1
        maxn = max(zNum, oNum, jNum)
        while maxn>0:
            if zNum>0:
                sys.stdout.write('Z'); zNum -= 1
            if oNum>0:
                sys.stdout.write('O'); oNum -= 1
            if jNum>0:
                sys.stdout.write('J'); jNum -= 1
            maxn -= 1
        sys.stdout.write('\n')
    except:
        break
