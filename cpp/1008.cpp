#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* left, TreeNode* right) : val(v), left(left), right(right) {}

    vector<int> intoVec() {
        vector<int> vec;
        queue<TreeNode*> q;
        q.push(this);
        while (!q.empty()) {
            TreeNode* t = q.front();
            if (t) {
                vec.push_back(t->val);
                q.push(t->left);
                q.push(t->right);
            } else {
                vec.push_back(-1);
            }
            q.pop();
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

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int N = preorder.size();
        if (!N) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> myStack;
        TreeNode* curr = root;
        for (int i = 1; i < N; i++) {
            int v = preorder[i];
            if (curr->val > v) {
                myStack.push(curr);
                curr->left = new TreeNode(v);
                curr = curr->left;
            } else {
                while (!myStack.empty() && myStack.top()->val < v) {
                    curr = myStack.top();
                    myStack.pop();
                }
                curr->right = new TreeNode(v);
                curr = curr->right;
            }
        }
        return root;
    }
};

int main() {
    Solution sol;
    // vector<int> vec = {8,5,1,7,10,12};
    vector<int> vec = {8,5,1,7,6,10,12};
    sol.bstFromPreorder(vec)->display();
    return 0;
}
