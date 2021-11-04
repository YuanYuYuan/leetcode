#include <queue>
#include <iostream>
#include <functional>

using namespace std;


struct TreeNode {
    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int val) : val(val) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        // return dfsMethod(root);
        return bfsMethod(root);
    }


private:
    int bfsMethod(TreeNode* root) {
        queue<TreeNode*> myQueue;
        if (!root) return 0;
        myQueue.push(root);
        int summ = 0;
        TreeNode* curr;
        while (!myQueue.empty()) {
            curr = myQueue.front();
            myQueue.pop();
            if (!curr->left && !curr->right) {
                summ += curr->val;
            } else {
                int val = curr->val * 10;
                if (curr->left) {
                    curr->left->val += val;
                    myQueue.push(curr->left);
                }
                if (curr->right) {
                    curr->right->val += val;
                    myQueue.push(curr->right);
                }
            }
        }
        return summ;
    }

    int dfsMethod(TreeNode* root) {
        if (!root) return 0;
        const static function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int summ) -> int {
            summ = summ * 10 + node->val;
            if (!node->left && !node->right) {
                return summ;
            } else {
                return (node->left ? dfs(node->left, summ) : 0) +
                    (node->right ? dfs(node->right, summ) : 0);
            }
        };
        return dfs(root, 0);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution sol;
    cout << sol.sumNumbers(root);
    return 0;
}


