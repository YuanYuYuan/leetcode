struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};
