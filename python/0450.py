from typing import Optional
from data_strcutres import TreeNode, tree_to_list, list_to_tree


class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return None
        if key > root.val:
            root.right = self.deleteNode(root.right, key)
            return root
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
            return root

        if not root.left and not root.right:
            return None
        elif not root.left:
            return root.right
        elif not root.right:
            return root.left
        else:
            curr = root.right
            while curr.left:
                curr = curr.left
            curr.left = root.left
            return root.right


print(tree_to_list(Solution().deleteNode(list_to_tree([5, 3, 6, 2, 4, 'N', 7]), 6)))
print(tree_to_list(Solution().deleteNode(list_to_tree([5, 3, 6, 2, 4, 'N', 7]), 5)))
