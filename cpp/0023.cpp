#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v) {}
    static ListNode* fromVec(vector<int> vec) {
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        for (auto v: vec) {
            node->next = new ListNode(v);
            node = node->next;
        }
        return dummy->next;
    }
    void print() {
        cout << this->val;
        ListNode* node = this->next;
        while (node) {
            cout << " -> " << node->val;
            node = node->next;
        }
        cout << endl;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists, int i = 0, int j = -1) {
        if (j == -1) j = lists.size() - 1;
        const int N = j - i + 1;
        if (N == 0) return nullptr;
        if (N == 1) return lists[i];
        if (N == 2) return mergeTwoLists(lists[i], lists[j]);
        const int m = (i + j) / 2;
        return mergeTwoLists(
            mergeKLists(lists, i, m),
            mergeKLists(lists, m+1, j)
        );
    }

private:
    ListNode* mergeTwoLists(ListNode* root1, ListNode* root2) {
        if (!root1)  return root2;
        if (!root2)  return root1;
        if (root1->val <= root2->val) {
            root1->next = mergeTwoLists(root1->next, root2);
            return root1;
        } else {
            root2->next = mergeTwoLists(root2->next, root1);
            return root2;
        }
    }
};

int main() {
    vector<int> vec1 = {1, 4, 5};
    vector<int> vec2 = {1, 3, 4};
    vector<int> vec3 = {2, 6};
    vector<ListNode*> lists = {
        ListNode::fromVec(vec1),
        ListNode::fromVec(vec2),
        ListNode::fromVec(vec3)
    };
    Solution().mergeKLists(lists)->print();
    return 0;
}
