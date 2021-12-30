#include <queue>
#include <iostream>

using namespace std;

class Node {
public:
    int val{};
    Node* left{};
    Node* right{};
    Node* next{};
    Node(int v) : val(v) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        // return bfs(root);
        // return dfs(root);
        return optimal(root);
    }

    Node* optimal(Node* root) {
        for (Node* layer = root; layer; layer = layer->left) {
            for (Node* curr = layer; curr && curr->left; curr = curr->next) {
                curr->left->next = curr->right;
                if (curr->next) curr->right->next = curr->next->left;
            }
        }
        return root;
    }

    Node* dfs(Node* root) {
        if (!root || !root->left) return root;
        root->left->next = root->right;
        if (root->next) root->right->next = root->next->left;
        dfs(root->left);
        dfs(root->right);
        return root;
    }

    Node* bfs(Node* root) {
        if (!root) return root;
        queue<Node*> myQueue;
        myQueue.push(root);
        while (!myQueue.empty()) {
            Node* prev = nullptr;
            for (int i = 0, N = myQueue.size(); i < N; i++) {
                Node* node = myQueue.front();
                myQueue.pop();
                if (node->left) myQueue.push(node->left);
                if (node->right) myQueue.push(node->right);
                if (i >= 1) {
                    prev->next = node;
                }
                prev = node;
            }
        }
        return root;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution sol;
    sol.connect(root);
    return 0;
}
