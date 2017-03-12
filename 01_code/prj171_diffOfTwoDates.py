#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

cumMonthLeapYear = [0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335]
cumMonthCommonYear = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334]

def isLeapYear(year):
    if (year%4==0 and year%100) or year%400==0:
        return True
    else:
        return False

def getDays(year, month, day):
    days = (year-1)*365 + (year-1)/4 - (year-1)/100 + (year-1)/400
    if isLeapYear(year):
        days += cumMonthLeapYear[month-1]
    else:
        days += cumMonthCommonYear[month-1]
    days += day
    return days

while True:
    try:
        date1 = raw_input()
        date2 = raw_input()
        days1 = getDays(int(date1[:4]), int(date1[4:6]), int(date1[6:]))
        days2 = getDays(int(date2[:4]), int(date2[4:6]), int(date2[6:]))
        print (abs(days1-days2)+1)
    except:
        break
