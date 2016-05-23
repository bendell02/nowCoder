#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

word2num = {'zero':'0', 'one':'1', 'two':'2', 'three':'3', 'four':'4', \
        'five':'5', 'six':'6', 'seven':'7', 'eight':'8', 'nine':'9'}

def resolve(numString):
    nums = numString.split()
    rlt = ''
    for num in nums:
        rlt += word2num[num]
    return int(rlt)

def getSum(string):
    string = string[:-2]
    num1, num2 = map(resolve, string.split(' + '))
    return (num1+num2)

while True:
    try:
        string = raw_input()
        if string == 'zero + zero =':
            break
        print getSum(string)
    except:
        break
