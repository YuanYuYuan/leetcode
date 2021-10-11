from data_strcutres import TreeNode
from collections import deque


class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        return self.dfs(root)

    def dfs(self, node: TreeNode) -> TreeNode:
        if node:
            node.left, node.right = self.dfs(node.right), self.dfs(node.left)
        return node

    def bfs(self, root: TreeNode) -> TreeNode:
        root_cp = root
        queue = deque([root_cp])
        while queue:
            node = queue.popleft()
            if not node:
                continue
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
            node.left, node.right = node.right, node.left
        return root
