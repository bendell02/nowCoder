#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

class Student:
    def __init__(self, name, grade):
        self.name = name
        self.grade = grade
    def __cmp__(self, other):
        if self.grade != other.grade:
            return -cmp(self.grade, other.grade)
        else:
            return  cmp(self.name, other.name)

def getGrade(weights, nums):
    rlt = 0
    for i in range(nums[0]):
        rlt += weights[nums[i+1]-1]
    return rlt

while True:
    try:
        N, M, G = map(int, raw_input().split())
        weights = map(int, raw_input().split())
        students = []
        for i in range(N):
            name, nums = raw_input().split(' ', 1)
            nums = map(int, nums.split())
            grade = getGrade(weights, nums)
            if grade >= G:
                students.append(Student(name, grade))
        print len(students)
        students.sort()
        for stu in students:
            print stu.name, stu.grade
    except:
        break
