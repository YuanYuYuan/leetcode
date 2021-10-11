struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
private:
    int dfs(TreeNode* node, int vmax) {
        int count = 0;
        if (node->val >= vmax) {
            count++;
            vmax = node->val;
        }
        if (node->left != nullptr) {
            count += dfs(node->left, vmax);
        }
        if (node->right != nullptr) {
            count += dfs(node->right, vmax);
        }
        return count;
    }
};
