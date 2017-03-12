#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def gcd(m, n):
    while n:
        m, n = n, m%n
    return m

while True:
    try:
        m, n = map(int, raw_input().split())
        print gcd(m, n)
    except:
        break
