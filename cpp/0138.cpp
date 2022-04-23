#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* origCursor = head;
        Node* copyCursor = new Node(origCursor->val);
        unordered_map<Node*, int> idx;
        vector<Node*> copyNodes = {copyCursor};
        idx[origCursor] = 0;
        origCursor = origCursor->next;
        for (int i = 1; origCursor; i++) {
            idx[origCursor] = i;
            copyCursor->next = new Node(origCursor->val);
            copyCursor = copyCursor->next;
            origCursor = origCursor->next;
            copyNodes.push_back(copyCursor);
        }
        origCursor = head;
        copyCursor = copyNodes[0];
        while (origCursor) {
            if (origCursor->random) {
                copyCursor->random = copyNodes[idx[origCursor->random]];
            }
            origCursor = origCursor->next;
            copyCursor = copyCursor->next;
        }
        return copyNodes[0];
    }
};
