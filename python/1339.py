from typing import Optional
from data_strcutres import TreeNode
from collections import deque


class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        def sum_of_subtree(node):
            val = node.val
            if node.left:
                val += sum_of_subtree(node.left)
            if node.right:
                val += sum_of_subtree(node.right)
            node.val = val
            return val
        root_val = sum_of_subtree(root)
        half = root_val // 2
        queue = deque([root])
        breakpoint = root_val
        min_dist = root_val
        while queue:
            node = queue.popleft()
            cur_dist = abs(node.val - half)
            if cur_dist < min_dist:
                breakpoint = node.val
                min_dist = cur_dist
            if node.val < half:
                continue
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        return ((root_val - breakpoint) * breakpoint) % (10**9+7)


root = TreeNode(1)
root.left = TreeNode(1)
#  root.right = TreeNode(3)

print(Solution().maxProduct(root))

