#include <vector>
#include <queue>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int v) : val(v) {}
    TreeNode(int v, TreeNode* left, TreeNode* right)
        : val(v), left(left), right(right) {}

    vector<int> intoVec() {
        queue<TreeNode*> que;
        vector<int> vec;
        que.push(this);
        while (!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();
            if (curr) {
                vec.push_back(curr->val);
                que.push(curr->left);
                que.push(curr->right);
            } else {
                vec.push_back(-1);
            }
        }
        return vec;
    }

    void display() {
        for (auto v: this->intoVec()) {
            cout << v << " ";
        }
        cout << endl;
    }
};

TreeNode* vecToTreeNode(const vector<int>& vec) {
    if (vec.size() == 0) return nullptr;
    TreeNode* root = new TreeNode(vec[0]);
    queue<TreeNode*> que;
    que.push(root);
    TreeNode* curr;

    int i = 1;
    while (!que.empty()) {
        curr = que.front();
        que.pop();
        if (i < vec.size() && vec[i] >= 0) {
            curr->left = new TreeNode(vec[i]);
            que.push(curr->left);
        }
        i++;
        if (i < vec.size() && vec[i] >= 0) {
            curr->right = new TreeNode(vec[i]);
            que.push(curr->right);
        }
        i++;
    }
    return root;
}


class Solution {
public:
    // bool isCousins(TreeNode* root, int x, int y) {
    //     queue<TreeNode*> que;
    //     que.push(root);
    //     bool found_one = false;
    //     while (!que.empty()) {
    //         int N = que.size();
    //         for (int i = 0; i < N; i++) {
    //             TreeNode* curr = que.front();
    //             que.pop();
    //             if (!curr) continue;
    //             if (curr->val == x || curr->val == y) {
    //                 if (found_one) {
    //                     return true;
    //                 } else {
    //                     found_one = true;
    //                 }
    //             }
    //             if (curr->left && curr->right) {
    //                 if (
    //                     (curr->left->val == x && curr->right->val == y) ||
    //                     (curr->right->val == x && curr->left->val == y)
    //                 ) return false;
    //             }
    //             if (curr->left) que.push(curr->left);
    //             if (curr->right) que.push(curr->right);
    //         }

    //         if (found_one) break;
    //     }
    //     return false;
    // }

    int xDepth = 0;
    int yDepth = 0;
    int xParent  = 0;
    int yParent  = 0;

    bool isCousins(TreeNode* root, int x, int y) {
        helper(root, -1, 0, x, y);
        return xDepth * yDepth * xParent * yParent != 0 &&
            xParent != yParent &&
            xDepth == yDepth;
    }

    void helper(TreeNode* curr, int parent, int depth, int x, int y) {
        if (xDepth * yDepth * xParent * yParent != 0) return;
        if (!curr) return;
        if (curr->val == x) {
            xDepth = depth;
            xParent = parent;
        } else if (curr->val == y) {
            yDepth = depth;
            yParent = parent;
        }
        if (curr->left) helper(curr->left, curr->val, depth + 1, x, y);
        if (curr->right) helper(curr->right, curr->val, depth + 1, x, y);
    }
};


int main() {
    // vector<int> vec = {1, 2, 3, -1, 4, 5, -1};
    // vector<int> vec = {1, 2, 3, 4};
    // vector<int> vec = {1, 2, 3, -1, 4, -1, 5};
    vector<int> vec = {1, 2, 3, -1, 4};
    TreeNode* node = vecToTreeNode(vec);
    node->display();
    // for (auto v: treeNodeToVec(node)) {
    //     cout << v << " ";
    // }
    Solution sol;
    cout << sol.isCousins(node, 2, 3);
    // cout << sol.recursiveWay(node, 2, 3);
    return 0;
}
