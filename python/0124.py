from typing import Optional
from data_strcutres import TreeNode


class Solution:
    max_sum = 0
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        assert root is not None
        self.max_sum = root.val
        def dfs(node):
            left = dfs(node.left) if node.left else 0
            right = dfs(node.right) if node.right else 0
            single_way = max(0, left, right)
            self.max_sum = max(
                self.max_sum,
                node.val + max(single_way, left+right)
            )
            return node.val + single_way
        dfs(root)
        return self.max_sum


#  root = TreeNode(-10)
#  root.left = TreeNode(9)
#  root.right = TreeNode(20)
#  root.right.left = TreeNode(15)
#  root.right.right = TreeNode(7)

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)

print(Solution().maxPathSum(root))
