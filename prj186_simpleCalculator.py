#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def compute(num1, num2, sym):
    if sym == '+':
        rlt = float(num1) + float(num2)
    elif sym == '-':
        rlt = float(num1) - float(num2)
    elif sym == '*':
        rlt = float(num1)*1.0*float(num2)
    else:
        rlt = float(num1)*1.0/float(num2)
    return rlt

def calculator(string):
    syms = string.split()
    newSyms = []; l = len(syms); idx = 0
    while idx < l:
        if syms[idx] == '*' or syms[idx] == '/':
            num = compute(newSyms[-1], syms[idx+1], syms[idx])
            newSyms[-1] = num; idx += 1
        else:
            newSyms.append(syms[idx])
        idx += 1
    rlt = float(newSyms[0]); l = len(newSyms); idx = 1
    while idx<l:
        if newSyms[idx]=='+' or newSyms[idx]=='-':
            rlt = compute(rlt, newSyms[idx+1], newSyms[idx])
            idx += 1
        idx += 1
    return rlt

while True:
    try:
        string = raw_input()
        if string == '0':
            break
        print '%.2f' % calculator(string)
    except:
        break

