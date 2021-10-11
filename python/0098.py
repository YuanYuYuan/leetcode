from typing import Optional
from data_strcutres import TreeNode

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        #  return self.iterative(root)
        return self.recursive(root)


    def recursive(self, root: Optional[TreeNode], vmin=float('-inf'), vmax=float('inf')) -> bool:
        if not root:
            return True
        return vmin < root.val < vmax \
            and self.recursive(root.left, vmin, root.val) \
            and self.recursive(root.right, root.val, vmax)


    def iterative(self, root: Optional[TreeNode]) -> bool:
        prev = None
        stack = []
        node = root
        while node or stack:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            if prev is not None and prev >= node.val:
                return False
            else:
                prev = node.val
            node = node.right
        return True




root = TreeNode(4)
root.left = TreeNode(2)
root.right = TreeNode(6)
root.left.left = TreeNode(1)
root.left.right = TreeNode(3)
root.right.left = TreeNode(5)
root.right.right = TreeNode(7)
print(Solution().isValidBST(root))
