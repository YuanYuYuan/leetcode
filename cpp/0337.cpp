#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v) {}
};

struct Pair {
    int include;
    int exclude;
    Pair(int x, int y) : include(x), exclude(y) {}
    int max() {
        return include >= exclude ? include : exclude;
    }
};

class Solution {
public:
    int rob(TreeNode* root) {
        return dfs(root).max();
    }

private:
    Pair dfs(TreeNode* node) {
        if (!node) return Pair(0, 0);
        Pair left = dfs(node->left);
        Pair right = dfs(node->right);
        return Pair(
            left.exclude + right.exclude + node->val,
            left.max() + right.max()
        );
    }
};

int main() {
    // TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->right = new TreeNode(3);
    // root->right->right = new TreeNode(1);

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(3);

    Solution sol;
    cout << sol.rob(root) << endl;
    return 0;
}
