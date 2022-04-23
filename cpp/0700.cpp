struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (val < root->val) {
            return searchBST(root->left, val);
        } else if (val > root->val) {
            return searchBST(root->right, val);
        } else {
            return root;
        }
    }
};
