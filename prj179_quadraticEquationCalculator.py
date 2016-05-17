#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

import math

def calCoe(chs):
    if chs=='' or chs=='+':
        coe = 1
    elif chs=='-':
        coe = -1
    else:
        coe = int(chs)
    return coe

def getCoe(chs):
    if len(chs)>=3 and chs[-3]=='x':
        idx = 2
        coe = calCoe(chs[:-3])
    elif chs[-1]=='x':
        idx = 1
        coe = calCoe(chs[:-1])
    else:
        idx = 0
        coe = calCoe(chs)
    return idx, coe

def resoleEquationString(chs, coes, sym):
    start = 0; end = 1; l = len(chs)
    while end<l:
        if chs[end]=='+' or chs[end]=='-':
            idx, coe = getCoe(chs[start:end])
            coes[idx] += (coe*sym)
            start = end
        end += 1
    else:
        idx, coe = getCoe(chs[start:end])
        coes[idx] += (coe*sym)

while True:
    try:
        part1, part2 = raw_input().strip().split('=')
        coes = [0]*3
        resoleEquationString(part1, coes, 1)
        resoleEquationString(part2, coes, -1)
        delta = coes[1]*coes[1] - 4*coes[0]*coes[2]
        if delta<0:
            print 'No Solution'
        else:
            x1 = (-coes[1]+math.sqrt(delta))/(2.0*coes[2])
            x2 = (-coes[1]-math.sqrt(delta))/(2.0*coes[2])
            if x1 > x2:
                x1, x2 = x2, x1
            print '%.2f %.2f' % (x1, x2)
    except:
        break
        
