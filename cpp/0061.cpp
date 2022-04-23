struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        int N = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            N += 1;
        }
        tail->next = head;
        ListNode* newTail = head;
        int newTailIdx = N - (k % N) - 1;
        for (int i = 0; i < newTailIdx; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};
