#include <string>
#include <vector>
#include <iostream>

using namespace std;


struct TrieNode {
    TrieNode* child[26] = {};
    bool isEndOfWord = false;
};

struct Trie {
    TrieNode* root = nullptr;
    Trie(vector<string>& words) {
        root = new TrieNode;
        for (const string word: words) {
            TrieNode* curr = root;
            for (const char c: word) {
                int idx = c - 'a';
                if (!curr->child[idx]) {
                    curr->child[idx] = new TrieNode;
                }
                curr = curr->child[idx];
            }
            curr->isEndOfWord = true;
        }
    }
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        trie = new Trie(words);
        visited = {};
        visited.push_back(trie->root);
    }

    bool query(char letter) {
        int idx = letter - 'a';
        bool found = false;
        vector<TrieNode*> new_visited = {trie->root};
        for (auto node: visited) {
            TrieNode* child = node->child[idx];
            if (child) {
                new_visited.push_back(child);
                if (child->isEndOfWord) {
                    found = true;
                }
           }
        }
        visited = new_visited;
        return found;
    }

private:
    Trie* trie = nullptr;
    vector<TrieNode*> visited = {};
};

int main() {
    // vector<string> vec = {"abc", "xyz"};
    // string str = "axyz";

    vector<string> vec = {"cd", "f", "kl"};
    string str = "abcdefghijkl";

    StreamChecker checker = StreamChecker(vec);
    for (const char c: str) {
        cout << c << ": " << checker.query(c) << endl;
    }
    return 0;
}
