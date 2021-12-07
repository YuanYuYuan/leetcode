#include <string>
#include <vector>
using namespace std;

const int NUM_CHAR = 26;

struct TrieNode {
    TrieNode* child[NUM_CHAR];
    bool isEndOfWord = false;
};

struct Trie {
    TrieNode* root = new TrieNode;
    Trie(vector<string>& words) {
        for (const string word: words) {
            TrieNode* curr = root;
            for (const char c: word) {
                int idx = c - 'a';
                if (!curr->child[idx]) {
                    curr->child[idx] = new TrieNode();
                }
                curr = curr->child[idx];
            }
            curr->isEndOfWord = true;
        }
    }
};
