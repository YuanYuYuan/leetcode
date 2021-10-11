from data_strcutres import TreeNode
from typing import Optional
from collections import deque

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        #  return self.dfs(p, q)
        return self.bfs(p, q)

    def dfs(self, p, q):
        if not p or not q:
            return p == q
        return p.val == q.val \
            and self.dfs(p.left, q.left) \
            and self.dfs(p.right, q.right)

    def bfs(self, p, q):
        pair_queue = deque([(p, q)])
        while pair_queue:
            x, y = pair_queue.popleft()
            if not x and not y:
                continue
            if (not x and y) or (x and not y):
                return False
            if x.val != y.val:
                return False
            pair_queue.append((x.left, y.left))
            pair_queue.append((x.right, y.right))
        return True



