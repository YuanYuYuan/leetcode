struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode* first = head;
        ListNode* second = first->next;
        ListNode* third = second->next;
        first->next = swapPairs(third);
        second->next = first;
        return second;
    }
};
