#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def grading(t, g1, g2, g3, gj):
    if abs(g1-g2)<=t:
        rlt = (g1+g2)/2.0
    else:
        a1 = abs(g3-g1); a2 = abs(g3-g2)
        if a1<=t and a2<=t:
            rlt = max(g1, g2, g3)
        elif a1<=t or a2<=t:
            if a1 < a2:
                rlt = (g1+g3)/2.0
            else:
                rlt = (g2+g3)/2.0
        else:
            rlt = gj
    return rlt

while True:
    try:
        p, t, g1, g2, g3, gj = map(int, raw_input().strip().split())
        print '%.1f' % (grading(t, g1, g2, g3, gj))
    except:
        break
