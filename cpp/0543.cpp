#include <stack>
#include <iostream>


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
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        dfs(root);
        return diameter;
    }

private:
    int diameter;
    int dfs(TreeNode* root) {
        if (root) {
            int left = dfs(root->left);
            int right = dfs(root->right );
            diameter = std::max(diameter, left + right);
            int depth = 1 + std::max(left, right);
            return depth;
        } else {
            return 0;
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution sol;
    std::cout << sol.diameterOfBinaryTree(root);
    return 0;
}
