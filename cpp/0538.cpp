#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v) {}
    vector<int> treeToVec() {
        vector<int> vec{};
        queue<TreeNode*> que;
        que.push(this);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            if (node) {
                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            } else {
                vec.push_back(-1);
            }
        }
        return vec;
    }
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }

    int dfs(TreeNode* root, int pre = 0) {
        if (!root) return 0;
        if (!root->right && !root->left) {
            root->val += pre;
            return root->val;
        }
        int right = (root->right) ? dfs(root->right, pre) : pre;
        root->val += right;
        if (root->left) {
            int left = dfs(root->left, root->val);
            return left;
        } else {
            return root->val;
        }
    }
};

int main() {
    // TreeNode* root = new TreeNode(4);
    // root->left = new TreeNode(1);
    // root->left->left = new TreeNode(0);
    // root->left->right = new TreeNode(2);
    // root->left->right->right = new TreeNode(3);
    // root->right = new TreeNode(6);
    // root->right->left = new TreeNode(5);
    // root->right->right = new TreeNode(7);
    // root->right->right->right = new TreeNode(8);

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(4);

    root = Solution().convertBST(root);
    for (auto v: root->treeToVec()) {
        cout << v << " ";
    }
    return 0;
}
