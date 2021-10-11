from typing import List, Optional
from data_strcutres import TreeNode


class Solution:
     def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        def build_trees(lst):
            if len(lst) == 0:
                return [None]
            out = []
            for i in range(len(lst)):
                for left in build_trees(lst[:i]):
                     for right in build_trees(lst[i+1:]):
                         root = TreeNode(lst[i])
                         root.left = left
                         root.right = right
                         out.append(root)
            return out
        return build_trees(list(range(1, n+1)))
