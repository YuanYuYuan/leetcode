from typing import List, Optional
from data_strcutres import TreeNode
from collections import deque


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        return self.with_list_comprehension(root)

    def with_list_comprehension(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        out, level = [], [root]
        while level:
            out.append([l.val for l in level])
            level = [kid for l in level for kid in [l.left, l.right] if kid]
        return out

    def with_deque(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        out = []
        queue = deque([root])

        while queue:
            cur = []
            for _ in range(len(queue)):
                node = queue.popleft()
                cur.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            out.append(cur)

        return out
