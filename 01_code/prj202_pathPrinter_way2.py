#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

import sys

def printDegs(degs):
    space = 0
    for deg in degs:
        if deg.strip() != '':
            sys.stdout.write(' '*space)
            sys.stdout.write(deg+'\n')
        space += len(deg)+1

def printSecDegs(degs, upDegs):
    degs = degs.split('\\')
    upDegs = upDegs.split('\\')
    ld = len(degs); lu = len(upDegs)
    lm = min(ld, lu)
    for i in range(lm):
        if degs[i] == upDegs[i]:
            degs[i] = ' '*len(upDegs[i])
        else:
            break
    printDegs(degs)

while True:
    try:
        N = input()
        if N == 0:
            break
        data = []
        for i in range(N):
            degs = raw_input()
            if degs[-1] == '\\':
                degs = degs[:-1]
            data.append(degs)
        data.sort()
        upDegs = ''
        for deg in data:
            printSecDegs(deg, upDegs)
            upDegs = deg
        sys.stdout.write('\n')
    except:
        break
