#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

while True:
    try:
        curses1 = {}; curses2 = {}
        while True:
            s = raw_input()
            if s == '@END@':
                break
            first, second = s.split('] ', 1)
            first = first[1:]
            curses1[first] = second
            curses2[second] = first
        N = input()
        while N:
            N -= 1
            first = raw_input()
            if first[0] == '[':
                first = first[1:-1]
                if curses1.has_key(first):
                    print curses1[first]
                else:
                    print 'what?'
            else:
                if curses2.has_key(first):
                    print curses2[first]
                else:
                    print 'what?'
    except:
        break
