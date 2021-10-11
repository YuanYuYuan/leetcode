from typing import List
from data_strcutres import TreeNode


class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        #  return self.recursive(root)
        #  return self.iterative(root)
        return self.morris(root)

    def morris(self, root: TreeNode) -> List[int]:
        out = []
        node = root
        while node:
            if node.left:
                prev = node.left
                while prev.right and prev.right is not node:
                    prev = prev.right
                if not prev.right:
                    prev.right = node
                    node = node.left
                else:
                    prev.right = None
                    out.append(node.val)
                    node = node.right
            else:
                out.append(node.val)
                node = node.right
        return out


    def iterative(self, root: TreeNode) -> List[int]:
        out = []
        stack = []
        node = root
        while node or stack:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            out.append(node.val)
            node = node.right
        return out


    def recursive(self, root: TreeNode) -> List[int]:
        def helper(node, lst):
            if node:
                helper(node.left, lst)
                lst.append(node.val)
                helper(node.right, lst)
        out = []
        helper(root, [])
        return out

    def recursive_oneliner(self, root: TreeNode, lst: List[int] = []) -> List[int]:
        return self.recursive(root.left, lst) + [root.val] + self.recursive(root.right, lst) if root else []
