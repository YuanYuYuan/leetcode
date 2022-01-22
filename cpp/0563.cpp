#include <iostream>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v) {}
};


class Solution {
public:
    int findTilt(TreeNode* root) {
        dfs(root);
        return summ;
    }

private:
    int summ = 0;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        summ += abs_diff(left, right);
        return node->val + left + right;
    }

    int abs_diff(int x, int y) {
        return x >= y ? x - y : y - x;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(9);
    root->right->right = new TreeNode(7);
    Solution sol;
    std::cout << sol.findTilt(root) << std::endl;
    return 0;
}
