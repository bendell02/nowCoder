#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

cumMonthLeapYear = [0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335]
cumMonthCommonYear = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334]
dayOfWeek = ["Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday" ]
monthStr = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]

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
        day, month, year = raw_input().split()
        day = int(day); year = int(year)
        month = monthStr.index(month)+1
        print dayOfWeek[getDays(year, month, day)%7]
    except:
        break
