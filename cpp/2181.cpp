struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if (!head->next) return nullptr;
        auto curr = head->next;
        int count = 0;
        while (curr->val != 0) {
            count += curr->val;
            curr = curr->next;
        }
        auto newNode = new ListNode(count);
        newNode->next = mergeNodes(curr);
        return newNode;
    }
};
