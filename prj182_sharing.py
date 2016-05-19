#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def getLength(head, nodes):
    length = 0
    while head != '-1':
        length += 1
        head = nodes[head]
    return length

def getFirstCommonNode(head1, head2, nodes):
    l1 = getLength(head1, nodes); l2 = getLength(head2, nodes)
    if l1<l2:
        l1, l2 = l2, l1
        head1, head2 = head2, head1
    for i in range(l1 - l2):
        head1 = nodes[head1]
    rlt = '-1'
    for i in range(l2):
        if head1 == head2:
            rlt = head1
            break
        head1 = nodes[head1]
        head2 = nodes[head2]
    return rlt

while True:
    try:
        head1, head2, N = raw_input().strip().split()
        nodes = dict(); N = int(N)
        for i in range(N):
            first, ch, second = raw_input().strip().split()
            nodes[first] = second
        print getFirstCommonNode(head1, head2, nodes)
    except:
        break
