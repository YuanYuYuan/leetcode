struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v) {}
};

// 2 (x + y) - (x + y) = nC => x + y = nC => x = nC - y
// 0 + x = (x + y) + x

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        bool cycleDetected = false;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                cycleDetected = true;
                break;
            }
        }

        if (!cycleDetected) return nullptr;
        while (head != fast) {
            head = head->next;
            fast = fast->next;
        }
        return head;
    }
};
