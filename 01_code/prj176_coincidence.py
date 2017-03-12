#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def longestCommonSequence(s1, s2):
    l1 = len(s1); l2 = len(s2)
    dp = [[0 for col in range(l2)] for row in range(l1)]

    dp[0][0] = 1 if s1[0]==s2[0] else 0
    for i in range(1, l1):
        dp[i][0] = 1 if s1[i]==s2[0] else 0
        dp[i][0] = max(dp[i-1][0], dp[i][0])
    for j in range(1, l2):
        dp[0][j] = 1 if s1[0]==s2[j] else 0
        dp[0][j] = max(dp[0][j-1], dp[0][j])

    for i in range(1, l1):
        for j in range(1, l2):
            if s1[i]==s2[j]:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+1)
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    return dp[l1-1][l2-1]

while True:
    try:
        s1 = raw_input()
        s2 = raw_input()
        print longestCommonSequence(s1, s2)
    except:
        break
