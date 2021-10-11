from data_strcutres import TreeNode


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        while True:
            if p.val == root.val or q.val == root.val:
                break
            p_sgn = root.val > p.val
            q_sgn = root.val > q.val
            if p_sgn == q_sgn:
                root = root.left if p_sgn else root.right
            else:
                break
        return root
