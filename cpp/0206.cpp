#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = head;

        while (cur->next != nullptr) {
            ListNode* keep = cur->next->next;
            cur->next->next = dummy->next;
            dummy->next = cur->next;
            cur->next = keep;
        }
        return dummy->next;
    }
};

int main() {
    Solution sol;
    ListNode* root = new  ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* reversed = sol.reverseList(root);
    while (reversed != nullptr) {
        cout << reversed->val << " ";
        reversed = reversed->next;
    }
    return 0;
}
