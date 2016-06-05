#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

firstLine = r"1234567890-="
secondeLine = 'QWERTYUIOP[]\\'
thirdLine = r"ASDFGHJKL;'"
forthLine = r"ZXCVBNM,./"

while True:
    try:
        s = raw_input()
        rlt = ''
        for ch in s:
            if ch in firstLine:
                rlt += firstLine[firstLine.index(ch)-1]
            elif ch in secondeLine:
                rlt += secondeLine[secondeLine.index(ch)-1]
            elif ch in thirdLine:
                rlt += thirdLine[thirdLine.index(ch)-1]
            elif ch in forthLine:
                rlt += forthLine[forthLine.index(ch)-1]
            else:
                rlt += ch
        print rlt
    except:
        break
