#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

sentence = raw_input()
stcList = sentence.split()
newSentence = ''
l = len(stcList)
for idx in range(l):
    if idx>0:
        newSentence = ' ' + newSentence
    newSentence = stcList[idx] + newSentence
print newSentence
