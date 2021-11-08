#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        if (root->left) {
            if (!root->left->left && !root->left->right) {
                sum += root->left->val;
            } else {
                sum += sumOfLeftLeaves(root->left);
            }
        }
        if (root->right) {
            sum += sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};

int main() {
    return 0;
}


