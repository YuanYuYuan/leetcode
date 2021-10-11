#include <vector>
#include <iostream>
using namespace std;


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
    vector<TreeNode*> generateTrees(int n) {
        return build_subtrees(1, n);
    }
private:
    vector<TreeNode*> build_subtrees(int beg, int end) {
        vector<TreeNode*> lst;
        if (beg > end) {
            lst.push_back(nullptr);
            return lst;
        }
        for (int i = beg; i <= end; i++) {
            for (auto left: build_subtrees(beg, i-1)) {
                for (auto right: build_subtrees(i+1, end)) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    lst.push_back(root);
                }
            }
        }
        return lst;
    }
};
