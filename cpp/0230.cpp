#include <vector>
#include <queue>
#include <iostream>
#include <functional>

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
    int kthSmallest(TreeNode* root, int k) {
        int res{};
        const static function<void(TreeNode*)> traverse = [&](TreeNode* node) {
            if (!node) return;
            traverse(node->left);
            k--;
            if (k == 0) {
                res = node->val;
                return;
            }
            traverse(node->right);
        };
        traverse(root);
        return res;
    }
};
