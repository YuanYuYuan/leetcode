#include <iostream>
#include <stack>


class Node {
public:
    int val;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* child = nullptr;
};


int main() {
    Node nodes[12];
    for (int i = 0; i < 12; i++) {
        nodes[i].val = i+1;
    }

    for (int i = 0; i < 5; i++) {
        nodes[i].next = &nodes[i+1];
        nodes[1+1].prev = &nodes[i];
    }

    for (int i = 6; i < 9; i++) {
        nodes[i].next = &nodes[i+1];
        nodes[1+1].prev = &nodes[i];
    }

    for (int i = 10; i < 11; i++) {
        nodes[i].next = &nodes[i+1];
        nodes[1+1].prev = &nodes[i];
    }

    nodes[2].child = &nodes[6];
    nodes[7].child = &nodes[10];

    Node* head = &nodes[0];
    Node* curr = head;
    std::stack<Node*> stk;

    while (curr) {
        bool hasNext = (curr->next != nullptr);
        bool hasChild = (curr->child != nullptr);
        std::cout << curr->val << ", " << hasNext << ", " << hasChild << std::endl;
        if (hasNext && hasChild) {
            std::cout << "case 1" << std::endl;
            stk.push(curr->next);
            curr->next = curr->child;
            curr->child->prev = curr;
            curr = curr->child;
        } else if (!hasNext && hasChild) {
            std::cout << "case 2" << std::endl;
            stk.push(curr->next);
            curr->next = curr->child;
            curr->child->prev = curr;
            curr = curr->child;
        } else if (hasNext && !hasChild) {
            std::cout << "case 3" << std::endl;
            curr = curr->next;
        } else {
            std::cout << "case 4" << std::endl;
            curr->next = stk.top();
            stk.top()->prev = curr;
            curr = stk.top();
            stk.pop();
        }
    }


    // std::cout << nodes[0].next->val << std::endl;
    return 0;
}

