#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def statFreq(freq, ch):
    numCh = ord(ch)
    if 65<=numCh<=90:
        freq[numCh-65] += 1

def outputFreq(freq):
    numCh = 65
    for num in freq:
        print (chr(numCh)+":"+str(num))
        numCh += 1

while True:
    try:
        line = raw_input()
        freq = [0]*26
        for ch in line:
            statFreq(freq, ch)
        outputFreq(freq)
    except:
        break

