#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return root ? (
            (low <= root->val && root->val <= high ? root->val : 0)
            + (root->val >= low ? rangeSumBST(root->left, low, high): 0)
            + (root->val <= high ? rangeSumBST(root->right, low, high): 0)
        ) : 0;
    }
};

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(18);
    Solution sol;
    std::cout << sol.rangeSumBST(root, 7, 15) << std::endl;
    return 0;
}
