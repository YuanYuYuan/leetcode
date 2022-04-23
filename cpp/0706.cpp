#include <algorithm>
#include <iostream>

using namespace std;

struct MyListNode {
    int key;
    int val;
    MyListNode* next;
    MyListNode(int k, int v) : key(k), val(v) { next = nullptr; }
};

class MyHashMap {
public:
    const static int SIZE = 997;
    int arr[SIZE]{};
    MyListNode* data[SIZE]{};
    MyHashMap() {
    }

    void put(int key, int value) {
        int k = hash(key);
        if (!data[k]) {
            data[k] = new MyListNode(key, value);
            return;
        }
        MyListNode* node = data[k];
        if (node->key == key) {
            node->val = value;
            return;
        }
        while (node->next) {
            if (node->next->key == key) {
                node->next->val = value;
                return;
            }
        }
        node->next = new MyListNode(key, value);
    }

    int get(int key) {
        MyListNode* node = data[hash(key)];
        while (node) {
            if (node->key == key) {
                return node->val;
            }
            node = node->next;
        }
        return -1;
    }

    void remove(int key) {
        int k = hash(key);
        if (!data[k]) return;
        MyListNode* node = data[k];
        if (node->key == key) {
            data[k] = node->next;
            delete node;
            return;
        }
        while (node->next) {
            if (node->next->key == key) {
                MyListNode* toDelete = node->next;
                node->next = toDelete->next;
                delete(toDelete);
                return;
            }
        }
    }

private:
    size_t hash(int key) {
        return key % SIZE;
    }
};


int main() {
    MyHashMap m;
    m.put(1, 1); // The map is now [[1,1]]
    m.put(2, 2); // The map is now [[1,1], [2,2]]
    cout << m.get(1) << endl;    // return 1, The map is now [[1,1], [2,2]]
    cout << m.get(3) << endl;    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    m.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    cout << m.get(2) << endl;    // return 1, The map is now [[1,1], [2,1]]
    m.remove(2); // remove the mapping for 2, The map is now [[1,1]]
    cout << m.get(2) << endl;    // return -1 (i.e., not found), The map is now [[1,1]]
    return 0;
}
