#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben


class WrongRecord(object):
    count = 1
    fileName = ''
    lineNum = 0

    def __init__(self, fileName, lineNum):
        self.fileName = fileName
        self.lineNum = lineNum

    def isSame(self, other):
        if (self.fileName == other.fileName) and (self.lineNum == other.lineNum):
            return True
        else:
            return False

    def output(self):
        return (self.fileName + ' ' + str(self.lineNum) + ' ' + str(self.count))
        
recordList = []
isFind = False
while True:
    try:
        fileName, lineNum = raw_input().split()
        fileName = fileName[-16:].split('\\')[-1]
        lineNum = int(lineNum)
        recordItem = WrongRecord(fileName, lineNum)
        isFind = False
        for item in recordList:
            if item.isSame(recordItem):
                item.count += 1
                isFind = True
                break
        if False == isFind:
            recordList.append(recordItem)
    except:
        break

recordList = recordList[-8:]
for item in recordList:
    print item.output()

        
