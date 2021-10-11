from typing import Optional
from data_strcutres import TreeNode


class Solution:
    found = False
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        self.found = False
        visited = set()
        def dfs(node):
            if node:
                if node.val in visited:
                    self.found = True
                    return
                else:
                    visited.add(k - node.val)
                    dfs(node.left)
                    dfs(node.right)
        dfs(root)
        return self.found

