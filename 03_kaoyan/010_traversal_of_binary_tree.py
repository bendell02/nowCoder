class TreeNode(object):
    def __init__(self,data):
        self.data = data
        self.left = 0
        self.right = 0

def inOrder(node):
    if node:
        inOrder(node.left)
        rlt.append(node.data)
        inOrder(node.right)

def constructTree(string):
    stack = []; idx = 0
    root = TreeNode(string[idx])
    stack.append(root); idx += 1
    while stack:
        preNode = stack.pop()
        if string[idx] != '#':
            node = TreeNode(string[idx])
            if preNode.left == 0:
                preNode.left = node
                stack.append(preNode)
                stack.append(node)
            else:
                preNode.right = node
                stack.append(node)
        else:
            if preNode.left == 0:
                preNode.left = None
                stack.append(preNode)
            else:
                preNode.right = None
        idx += 1
    return root

rlt = []
while True:
    try:
        rlt = []
        string = raw_input().strip()
        root = constructTree(string)
        inOrder(root)
        finalRlt = ' '.join(rlt) + ' '
        print finalRlt
    except:
        break
                
