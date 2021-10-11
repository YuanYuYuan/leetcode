from data_strcutres import TreeNode
from typing import Optional


class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root:
            return subRoot is None

        def match_subtree(p, q):
            if p and q:
                return (
                    p.val == q.val \
                    and match_subtree(p.left, q.left) \
                    and match_subtree(p.right, q.right)
                )
            else:
                if not p and not q:
                    return True
                else:
                    return False

        return match_subtree(root, subRoot) \
            or self.isSubtree(root.left, subRoot) \
            or self.isSubtree(root.right, subRoot)
