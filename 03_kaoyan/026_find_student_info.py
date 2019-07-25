# -*- coding: utf-8 -*-
class Student:
    def __init__(self, ID, info):
        self.ID = ID
        self.info = info
    def __cmp__(self, other):
        return cmp(self.ID, other.ID)

def biSearch(idx, N):
    start = 0; end = N-1; rlt = -1
    while start <= end:
        mid = (start+end)>>1
        if students[mid].ID == idx:
            rlt = mid
            break
        elif students[mid].ID > idx:
            end = mid-1
        else:
            start = mid+1
    return rlt

N = input(); i = 0
students = [0]*N
while i < N:
    ID, other = raw_input().split(' ', 1)
    info = ID + ' ' + other
    ID = int(ID)
    students[i] = Student(ID, info)
    i += 1

students.sort()
M = input(); i = 0
while i < M:
    idx = input()
    rlt = biSearch(idx, N)
    if rlt == -1:
        print 'No Answer!'
    else:
        print students[rlt].info
    i += 1
