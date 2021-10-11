from data_strcutres import TreeNode
from typing import Optional
from collections import deque


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        #  return self.dfs(root)
        return self.bfs(root)

    def dfs(self, root):
        return 1 + max(self.dfs(root.left), self.dfs(root.right)) if root else 0

    def bfs(self, root):
        if not root:
            return 0
        queue = deque([root])
        depth = 0
        while queue:
            depth += 1
            for _ in range(len(queue)):
                node = queue.popleft()
                if not node:
                    continue
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return depth
