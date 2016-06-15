#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def getExp(num):
    exps = []
    idx = 0
    while num:
        if num%2:
            exps.insert(0, idx)
        num /= 2
        idx += 1
    return exps

def getStr(num):
    exps = getExp(num)
    rlt = ''
    for exp in exps:
        if exp == 0:
            rlt += '2(0)+'
        elif exp == 1:
            rlt += '2+'
        elif exp == 2:
            rlt += '2(2)+'
        else:
            rlt += '2(' + getStr(exp) + ')+'
    return rlt[:-1]

while True:
    try:
        num = input()
        print getStr(num)
    except:
        break
