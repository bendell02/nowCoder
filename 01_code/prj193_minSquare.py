#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

MAXN = float('inf')
MINN = float('-inf')

while True:
    try:
        lb_x = lb_y = MAXN
        rt_x = rt_y = MINN
        while True:
            x, y = map(int, raw_input().split())
            if x==0 and y==0:
                break
            if x<lb_x:
                lb_x = x
            if y<lb_y:
                lb_y = y
            if x>rt_x:
                rt_x = x
            if y>rt_y:
                rt_y = y
        if lb_x==MAXN or lb_y==MAXN or rt_x==MINN or rt_y==MINN:
            break
        else:
            print lb_x, lb_y, rt_x, rt_y
    except:
        break
