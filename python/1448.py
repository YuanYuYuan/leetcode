from data_strcutres import TreeNode

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(node, vmax):
            count = 0
            if node.val >= vmax:
                count += 1
            vmax = max(vmax, node.val)
            if node.left:
                count += dfs(node.left, vmax)
            if node.right:
                count += dfs(node.right, vmax)
            return count
        return dfs(root, root.val)
