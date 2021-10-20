#include <iostream>
#include <string>

using namespace std;


class Trie {
public:
    Trie* child[26] = {};   // <- Passed
    // Trie child[26] = {};       // <- Error: field has incomplete type Trie
    bool isWord = false;

    /** Initialize your data structure here. */
   Trie() {
        this->isWord = false;
    }

    // [>* Inserts a word into the trie. <]
    // void insert(string word) {
    //     Trie* curr = this;
    //     for (auto c: word) {
    //         int key =  c - 'a';
    //         if (!curr->child[key]) {
    //             curr->child[key] = new Trie();
    //         }
    //         curr = curr->child[key];
    //     }
    //     curr->isWord = true;
    // }

    // [>* Returns if the word is in the trie. <]
    // bool search(string word) {
    //     Trie* curr = this;
    //     for (auto c: word) {
    //         int key =  c - 'a';
    //         if (!curr->child[key]) {
    //             return false;
    //         } else {
    //             curr = curr->child[key];
    //         }
    //     }
    //     return curr->isWord;
    // }

    // [>* Returns if there is any word in the trie that starts with the given prefix. <]
    // bool startsWith(string prefix) {
    //     Trie* curr = this;
    //     for (auto c: prefix) {
    //         int key =  c - 'a';
    //         if (!curr->child[key]) {
    //             return false;
    //         } else {
    //             curr = curr->child[key];
    //         }
    //     }
    //     return true;
    // }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << endl;   // return True
    cout << obj->search("app") << endl;     // return False
    cout << obj->startsWith("app") << endl; // return True
    obj->insert("app");
    cout << obj->search("app") << endl;     // return True
    return 0;
}
