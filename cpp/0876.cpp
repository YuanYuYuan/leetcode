#include <vector>
#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v) {}
    string display() {
        ListNode* curr = this;
        string ctx = to_string(curr-> val);
        curr = curr->next;
        while (curr) {
            ctx += ("->" + to_string(curr->val));
            curr = curr->next;
        }
        return ctx;
    }
    static ListNode* fromVec(const vector<int>& vec) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        for (auto v: vec) {
            curr->next = new ListNode(v);
            curr = curr->next;
        }
        return head->next;
    }
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    ListNode* node = ListNode::fromVec(vec);
    Solution sol;
    cout << node->display() << endl;
    cout << sol.middleNode(node)->display() << endl;
    return 0;
}
