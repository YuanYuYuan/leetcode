#include <vector>
#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v) {}
    static TreeNode* fromVec(vector<int> vec) {
        if (vec.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(vec[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (i < vec.size()) {
            TreeNode* left = new TreeNode(vec[i]);
            q.front()->left = left;
            q.push(left);
            i += 1;

            if (i >= vec.size()) break;

            TreeNode* right = new TreeNode(vec[i]);
            q.front()->right = right;
            q.push(right);
            i += 1;

            q.pop();
        }
        return root;
    }
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)  {
        vector<int> vec1, vec2;
        inorder(root1, vec1);
        inorder(root2, vec2);
        const int N1 = vec1.size();
        const int N2 = vec2.size();

        int i = 0;
        int j = 0;
        vector<int> res = {};
        while (i < N1 && j < N2) {
            res.push_back(
                (vec1[i] < vec2[j])
                ? vec1[i++]
                : vec2[j++]
            );
        }
        for (; i < N1; i++) res.push_back(vec1[i]);
        for (; j < N2; j++) res.push_back(vec2[j]);
        return res;
    }
private:
    void inorder(TreeNode* root, vector<int>& vec) {
        if (root) {
            if (root->left) inorder(root->left, vec);
            vec.push_back(root->val);
            if (root->right) inorder(root->right, vec);
        }
    }
};

int main() {
    vector<int> vec1 = {2, 1, 4};
    vector<int> vec2 = {1, 0, 3};
    Solution sol;
    for (auto v: sol.getAllElements(
        TreeNode::fromVec(vec1),
        TreeNode::fromVec(vec2)
    )) {
        cout << v << endl;
    }
    return 0;
}

