#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

while True:
    try:
        N = int(raw_input())
        content = dict()
        while N:
            N -= 1
            index, value = map(int, raw_input().split())
            if content.has_key(index):
                content[index] += value
            else:
                content[index] = value

        newContent = sorted(content.iteritems(), key=lambda asd:asd[0])
        for c in newContent:
            print c[0],c[1]
    except:
        break
