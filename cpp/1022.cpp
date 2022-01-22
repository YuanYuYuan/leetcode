#include <functional>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v) {}
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int val = 0) {
        if (!root) return 0;
        val = (val << 1) + root->val;
        if (!root->left && !root->right) return val;
        return sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    Solution sol;
    cout << sol.sumRootToLeaf(root) << endl;
    return 0;
}
