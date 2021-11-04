#include <limits.h>
#include <algorithm>
#include <iostream>

struct StackNode {
    int val = 0;
    int min = INT_MAX;
    StackNode* next = nullptr;
    StackNode() {}
    StackNode(int val, int min) : val(val), min(min) {}
};

class MinStack {
public:
    // initialize the stack object
    MinStack() {
        cursor = new StackNode();
    }

    // pushes the element val onto the stack
    void push(int val) {
        StackNode* node = new StackNode(val, std::min(val, cursor->min));
        node->next = cursor;
        cursor = node;
    }

    // removes the element on the top of the stack
    void pop() {
        cursor = cursor->next;
    }

    // gets the top element of the stack
    int top() {
        return cursor->val;
    }

    // retrieves the minimum element in the stack
    int getMin() {
        return cursor->min;
    }
private:
    StackNode* cursor;
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(3);
    obj->push(1);
    obj->push(-1);
    obj->push(2);
    obj->pop();
    std::cout << obj->top() << std::endl;
    std::cout << obj->getMin() << std::endl;
    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
