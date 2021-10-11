from typing import Optional
from data_strcutres import TreeNode


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        return self.morris(root, k)
        #  return self.iterative(root, k)
        #  return self.recursive(root, k)

    def morris(self, root: Optional[TreeNode], k: int) -> int:
        lst = []
        while root:
            if root.left:
                prev = root.left
                while prev.right and prev.right != root:
                    prev = prev.right
                if not prev.right:
                    prev.right = root
                    root = root.left
                else:
                    prev.right = None
                    lst.append(root.val)
                    if len(lst) >= k:
                        break
                    root = root.right
            else:
                lst.append(root.val)
                if len(lst) >= k:
                    break
                root = root.right
        return lst[k-1]


    def iterative(self, root: Optional[TreeNode], k: int) -> int:
        stack, lst = [], []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            lst.append(root.val)
            if len(lst) >= k:
                break
            root = root.right
        return lst[k-1]

    def recursive(self, root: Optional[TreeNode], k: int) -> int:
        def helper(node, lst):
            if node:
                helper(node.left, lst)
                lst.append(node.val)
                if len(lst) >= k: return
                helper(node.right, lst)
        lst = []
        helper(root, lst)
        return lst[k-1]

root = TreeNode(3)
root.left = TreeNode(1)
root.left.right = TreeNode(2)
root.right = TreeNode(4)

print(Solution().kthSmallest(root, 1))
