#include <functional>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v) {}
};

string tree2String(TreeNode* root) {
    if (!root) return "";
    queue<TreeNode*> que;
    que.push(root);
    string res;
    while (!que.empty()) {
        TreeNode* node = que.front();
        que.pop();
        res += (res == "" ? "" : ", ");
        if (node) {
            res += to_string(node->val);
            que.push(node->left);
            que.push(node->right);
        } else {
            res += "N";
        }
    }
    return res;
}

TreeNode* vec2Tree(vector<int> vec) {
    if (vec.empty()) return nullptr;
    TreeNode* root = new TreeNode(vec[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while (i < vec.size()) {
        TreeNode* curr = que.front();
        que.pop();
        if (vec[i] != -1) {
            curr->left = new TreeNode(vec[i]);
            que.push(curr->left);
        }
        i += 1;
        if (vec[i] != -1) {
            curr->right = new TreeNode(vec[i]);
            que.push(curr->right);
        }
        i += 1;
    }
    return root;
}

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) {
                root = root->right;
            } else if (!root->right) {
                root = root->left;
            } else {
                auto toSwap = root->right;
                while (toSwap->left) {
                    toSwap = toSwap->left;
                }
                root->val = toSwap->val;
                root->right = deleteNode(root->right, toSwap->val);
            }
        }
        return root;
    }
};

int main() {
    vector<int> vec = {5, 3, 6, 2, 4, -1, 7};
    TreeNode* root = vec2Tree(vec);
    cout << tree2String(root) << endl;
    Solution sol;
    sol.deleteNode(root, 3);
    cout << tree2String(root) << endl;
}
