#include <random>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* data;
    Solution(ListNode* head) {
        data = head;
    }

    // reservoir sampling
    int getRandom() {
        ListNode* node = data;
        int res{};
        for (int len = 1; node; len++) {
            if (rand() % len == 0) {
                res = node->val;
            }
            node = node->next;
        }
        return res;
    }
};
