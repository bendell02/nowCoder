#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def getSum(A, B, m, n):
    C = [[0 for col in range(n)] for row in range(m)]
    for i in range(m):
        for j in range(n):
            C[i][j] = A[i][j] + B[i][j]
    return C

def statZeroLines(C, m, n):
    rows = [1]*m; cols = [1]*n
    for i in range(m):
        for j in range(n):
            if C[i][j] != 0:
                rows[i] = 0; cols[j] = 0
    rlt = sum(rows) + sum(cols)
    return rlt

while True:
    try:
        m, n = map(int, raw_input().split())
        A = [[0 for col in range(n)] for row in range(m)]
        B = [[0 for col in range(n)] for row in range(m)]
        for i in range(m):
            A[i] = map(int, raw_input().split())
        for i in range(m):
            B[i] = map(int, raw_input().split())
        C = getSum(A, B, m, n)
        print statZeroLines(C, m, n)
    except:
        break
