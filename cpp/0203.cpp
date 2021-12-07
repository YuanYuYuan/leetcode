#include <iostream>

using namespace std;


struct ListNode {
    int val{};
    ListNode* next{};
    ListNode(): val(0), next(nullptr) {};
    ListNode(int val): val(val), next(nullptr) {};
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // return iterative(head, val);
        return recursive(head, val);
    }

    ListNode* iterative(ListNode* head, int val) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curr = dummy;
        while (curr->next) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }

    ListNode* recursive(ListNode* head, int val) {
        if (!head) return nullptr;
        head->next = recursive(head->next, val);
        return head->val == val ? head->next : head;
    }
};

int main() {
    ListNode* head = new ListNode(10);
    Solution sol;
    sol.removeElements(head, 10);
    return 0;
}
