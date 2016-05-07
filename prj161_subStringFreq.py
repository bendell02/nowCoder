#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

class Node:
    def __init__(self):
        self.left = self.right = None
        self.freq = 0

class Trie:
    def __init__(self):
        self.root = Node()

    def add(self, word):
        node = self.root
        for ch in word:
            if ch == '0':
                if node.left == None:
                    node.left = Node()
                node = node.left
            else:
                if node.right == None:
                    node.right = Node()
                node = node.right
            node.freq += 1

def preOrder(node, s):
    if node:
        if node.freq > 1:
            print "%s %d" % (s, node.freq)
        preOrder(node.left, s+'0')
        preOrder(node.right, s+'1')

while True:
    try:
        s = raw_input()
        tree = Trie()
        l = len(s)
        for i in range(l):
            tree.add(s[i:l])
        preOrder(tree.root, '')
    except:
        break
