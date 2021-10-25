#include <math.h>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};


class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode* curr;

        int left_level = 0;
        curr = root;
        while (curr) {
            curr = curr->left;
            left_level += 1;
        }

        int right_level = 0;
        curr = root;
        while (curr) {
            curr = curr->right;
            right_level += 1;
        }

        if (left_level == right_level) {
            // return (1 << left_level) - 1;
            return pow(2, left_level) - 1;
        } else {
            return 1 + (root->left ? countNodes(root->left) : 0) + (root->right ? countNodes(root->right) : 0);
        }
    }
};
