#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v) : val(v) {}
};


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int val = 0;
        while (head) {
            val <<= 1;
            val += head->val;
            head = head->next;
        }
        return val;
    }
};

int main() {
    ListNode* node = new ListNode(1);
    node->next = new ListNode(0);
    node->next->next = new ListNode(1);
    Solution sol;
    std::cout << sol.getDecimalValue(node);
    return 0;
}
