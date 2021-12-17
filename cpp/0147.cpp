#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        for (auto j = head; j; j = j->next)
            for (auto i = head; i != j; i = i->next)
                if (i->val > j->val)
                    swap(i->val, j->val);
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    Solution sol;
    head = sol.insertionSortList(head);
    while (head) {
        std::cout << head->val << std::endl;
        head = head->next;
    }
    return 0;
}
