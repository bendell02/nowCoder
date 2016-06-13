#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

# 按照 牛客673854  的思路写得

import Queue

chessSize = 6
direction = [[-1, 0],  [1, 0], [0, -1], [0, 1]]
class Point:
    def __init__(self, x, y, s):
        self.x = x
        self.y = y
        self.s = s

def BFS(cost, chess, sx, sy):
    cost[sx][sy][1] = 0
    q = Queue.Queue()
    q.put(Point(sx, sy, 1))
    while not q.empty():
        now = q.get()
        for i in range(4):
            nx = now.x + direction[i][0]
            ny = now.y + direction[i][1]
            if (nx<0 or nx>=chessSize or ny<0 or ny>=chessSize):
                continue
            tempCost = chess[nx][ny]*now.s
            tempState = (tempCost%4) + 1
            if cost[nx][ny][tempState]==-1 or cost[nx][ny][tempState]>cost[now.x][now.y][now.s]+tempCost:
                q.put(Point(nx, ny, tempState))
                cost[nx][ny][tempState] = cost[now.x][now.y][now.s]+tempCost

N = input()
for n in range(N):
    chess = [0]*chessSize
    for i in range(chessSize):
        chess[i] = map(int, raw_input().split())
    cost = [[[-1 for s in range(5)] for col in range(chessSize+1)] for row in range(chessSize+1)]
    sx, sy, ex, ey = map(int, raw_input().split())
    BFS(cost, chess, sx, sy)
    rlt = -1
    for i in range(1, 5):
        if cost[ex][ey][i] != -1:
            if rlt==-1 or rlt>cost[ex][ey][i]:
                rlt = cost[ex][ey][i]
    print rlt
