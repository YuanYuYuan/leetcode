from typing import Optional

class TreeNode:
   def __init__(self, val=0, left=None, right=None):
       self.val = val
       self.left = left
       self.right = right

class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        startPath = self.traverse(root, startValue)
        destPath = self.traverse(root, destValue)

        i = 0
        N = min(len(startPath), len(destPath))
        while i < N and startPath[i] == destPath[i]:
            i += 1

        #  print(startPath, destPath, i)
        res = str('U' * (len(startPath) - i)) + destPath[i:]
        return res

    def traverse(self, node: Optional[TreeNode], destValue: int) -> str:
        def backtrace(node: Optional[TreeNode], lst) -> bool:
            if not node: return False
            if node.val == destValue: return True
            if backtrace(node.left, lst):
                lst.append('L')
                return True
            if backtrace(node.right, lst):
                lst.append('R')
                return True
            return False
        path = []
        backtrace(node, path)
        return "".join(path[::-1])

#  t = TreeNode(5)
#  t.left = TreeNode(1)
#  t.left.left = TreeNode(3)
#  t.right = TreeNode(2)
#  t.right.left = TreeNode(6)
#  t.right.right = TreeNode(4)

t = TreeNode(1)
t.left = TreeNode(3)
t.left.left = TreeNode(7)
t.left.left.left = TreeNode(6)
t.right = TreeNode(8)
t.right.left = TreeNode(4)
t.right.right = TreeNode(5)
t.right.right.right = TreeNode(2)

#  destValue = 6
#  path = ""

#  def traverse(node: Optional[TreeNode], path):
#      if not node:
#          return
#      if node.val == destValue:
#          print(path)
#      else:
#          if node.left:
#              traverse(node.left, path + "L")
#          if node.right:
#              traverse(node.right, path + "R")

#  traverse(t, "")
#  print(path)
#  print(Solution().traverse(t, 3))
#  print(Solution().getDirections(t, 3, 6))
#  print(Solution().getDirections(t, 3, 1))
#  print(Solution().getDirections(t, 4, 5))
#  print(Solution().getDirections(t, 3, 5))
#  print(Solution().getDirections(t, 6, 4))
print(Solution().getDirections(t, 2, 1))
