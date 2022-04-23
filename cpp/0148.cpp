#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void print() {
        auto node = this;
        cout << node->val;
        node = node->next;
        while (node) {
            cout << " -> " << node->val;
            node = node->next;
        }
        cout << endl;
    }

    static auto fromVec(vector<int> vec) {
        auto dummy = new ListNode(0);
        auto curr = dummy;
        for (auto v: vec) {
            curr->next = new ListNode(v);
            curr = curr->next;
        }
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        auto remain = bisect(head);
        if (!remain) return sortList(head);
        return merge(sortList(head), sortList(remain));
    }

    ListNode* bisect(ListNode* node) {
        if (!node) return nullptr;
        auto slow = node;
        auto fast = node;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto remain = slow->next;
        slow->next = nullptr;
        return remain;
    }

    ListNode* merge(ListNode* a, ListNode* b) {
        if (!a) return b;
        if (!b) return a;
        if (a->val <= b->val) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(b->next, a);
            return b;
        }
    }
};


int main() {
    vector<int> vec = {-1,5,3,4,0};
    // vector<int> vec = { 1 };
    Solution sol;
    auto head = ListNode::fromVec(vec);
    // auto remain = sol.bisect(head);
    // head->print();
    // if (remain) { remain->print(); }
    auto res = sol.sortList(head);
    res->print();
    return 0;
}
