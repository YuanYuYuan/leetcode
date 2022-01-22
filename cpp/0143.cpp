#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v) {}
    string into_string() {
        string ctx = to_string(this->val);
        ListNode* curr = this->next;
        while (curr) {
            ctx += "->" + to_string(curr->val);
            curr = curr->next;
        }
        return ctx;
    }
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* preMid = findPreMidium(head);
        ListNode* half = preMid->next;
        preMid->next = nullptr;
        head = mergeTwoLists(head, reverseList(half));
    }

private:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* root = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return root;
    }

    ListNode* findPreMidium(ListNode* head) {
        if (!head) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        l1->next = mergeTwoLists(l2, l1->next);
        return l1;
    }

};

ListNode* vecToList(vector<int> vec) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (auto v: vec) {
        curr->next = new ListNode(v);
        curr = curr->next;
    }
    return dummy->next;
}

int main() {
    Solution sol;
    vector<int> e = {0, 2, 4, 6, 8};
    vector<int> o = {1, 3, 5, 7, 9, 11};
    ListNode* even = vecToList(e);
    ListNode* odd = vecToList(o);
    sol.reorderList(odd);
    cout << "Even: " << even->into_string() << endl;
    cout << "Odd: " << odd->into_string() << endl;
    // cout << "Merge: " << mergeTwoLists(even, odd)->into_string() << endl;
    // cout << "Mid of even: " << findMidium(even)->into_string() << endl;
    // cout << "Mid of odd: " << findMidium(odd)->into_string() << endl;
    // cout << "Reverse of even: " << reverseList(even)->into_string() << endl;
    // cout << "Reverse of odd: " << reverseList(odd)->into_string() << endl;
}
