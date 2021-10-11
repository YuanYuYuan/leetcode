from data_strcutres import TreeNode
from typing import List, Optional

class Solution:
    def buildTree(self, preorder, inorder):
        #  return self.use_stop(preorder, inorder)
        return self.count_index(preorder, inorder)

    def use_stop(self, preorder, inorder):
        preorder = preorder[::-1]
        inorder = inorder[::-1]
        def build(stop):
            if inorder and inorder[-1] != stop:
                root = TreeNode(preorder.pop())
                root.left = build(root.val)
                inorder.pop()
                root.right = build(stop)
                return root
        return build(None)


    def count_index(self, preorder, inorder):
        if inorder:
            ind = inorder.index(preorder.pop(0))
            root = TreeNode(inorder[ind])
            root.left = self.buildTree(preorder, inorder[0:ind])
            root.right = self.buildTree(preorder, inorder[ind+1:])
            return root

#  tree = Solution().buildTree([1, 2, 3], [2, 1, 3])
tree = Solution().buildTree(
    [1, 2, 4, 8, 9, 5, 3, 6, 7],
    [8, 4, 9, 2, 5, 1, 6, 3, 7]
)
