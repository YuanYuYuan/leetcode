from collections import deque

class ListNode:
   def __init__(self, val=0, next=None):
       self.val = val
       self.next = next

class Node:
    def __init__(self, val: int):
        self.val = val
        self.right = None
        self.left = None

TreeNode = Node

def tree_to_list(tree):
    out = []
    queue = deque([tree])
    while queue:
        node = queue.popleft()
        if node:
            out.append(node.val)
            queue.append(node.left)
            queue.append(node.right)
        else:
            out.append('N')
    return out

def list_to_tree(lst):
    if not lst or lst[0] == 'N':
        return None

    root = TreeNode(lst[0])
    queue = deque([root])
    lst_iter = iter(lst[1:])
    while queue:
        node = queue.popleft()
        try:
            val = next(lst_iter)
            if val != 'N':
                node.left = TreeNode(val)
                queue.append(node.left)
            val = next(lst_iter)
            if val != 'N':
                node.right = TreeNode(val)
                queue.append(node.right)
        except StopIteration:
            break
    return root
