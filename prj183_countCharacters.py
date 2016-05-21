#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def countChs(requires, chs):
    freq = [0]*256
    for ch in chs:
        freq[ord(ch)] += 1
    for ch in requires:
        print '%c %d' % (ch, freq[ord(ch)])

while True:
    try:
        requires = raw_input()
        if requires == '#':
            break
        chs = raw_input()
        countChs(requires, chs)
    except:
        break
