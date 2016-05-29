#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

class Student:
    def __init__(self, ID, name, grade):
        self.ID = ID
        self.name = name
        self.grade = grade

def myCmp1(a, b):
    return cmp(a.ID, b.ID)

def myCmp2(a, b):
    if a.name != b.name:
        return cmp(a.name, b.name)
    else:
        return cmp(a.ID, b.ID)

def myCmp3(a, b):
    if a.grade != b.grade:
        return cmp(a.grade, b.grade)
    else:
        return cmp(a.ID, b.ID)

idx = 0
while True:
    try:
        idx += 1
        N, C = map(int, raw_input().split())
        if N==0 and C==0:
            break
        students = [0]*N
        for i in range(N):
            ID, name, grade = raw_input().split()
            students[i] = Student(ID, name, int(grade))
        exec('students.sort(myCmp'+str(C)+')')
        print 'Case: %d' % idx
        for stu in students:
            print stu.ID, stu.name, stu.grade
    except:
        break
