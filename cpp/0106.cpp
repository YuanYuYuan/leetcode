#include <vector>
#include <functional>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorder_key;
        for (int i{}; i < inorder.size(); i++) {
            inorder_key[inorder[i]] = i;
        }
        const static function<TreeNode*(int, int)> recur = [&](int lo, int hi) -> TreeNode* {
            if (lo > hi) return nullptr;
            int val = postorder.back();
            int mid = inorder_key[val];
            postorder.pop_back();
            TreeNode* right = recur(mid+1, hi);
            TreeNode* left = recur(lo, mid-1);
            return new TreeNode(val, left, right);
        };
        return recur(0, inorder.size() - 1);
    }
};
