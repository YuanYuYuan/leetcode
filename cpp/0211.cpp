#include <string>
#include <iostream>

using namespace std;

struct TrieNode {
    TrieNode* child[26];
    bool isWord;
};


class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (const auto& c: word) {
            if (!node->child[c - 'a']) {
                node->child[c - 'a'] = new TrieNode();
            }
            node = node->child[c - 'a'];
        }
        node->isWord = true;
    }

    bool search(string word) {
        cout << word << ": ";
        return exactSearch(word, 0, root);
    }

    // bool search(string word) {
    //     cout << word << ": ";
    //     TrieNode* node = root;
    //     for (const auto& c: word) {
    //         node = node->child[c - 'a'];
    //         if (!node) return false;
    //     }
    //     return node->isWord;
    // }

    bool exactSearch(string& word, int idx, TrieNode* node) {
        if (!node) return false;
        for (int i = idx; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                // if (i == word.size() - 1) return true;
                for (int j = 0; j < 26; j++) {
                    if (exactSearch(word, i+1, node->child[j])) {
                        return true;
                    }
                }
                return false;
            } else {
                node = node->child[c - 'a'];
                if (!node) return false;
            }
        }
        return node->isWord;
    }
private:
    TrieNode* root;
};

int main() {
    WordDictionary wordDictionary = WordDictionary();

    // wordDictionary.addWord("bad");
    // wordDictionary.addWord("dad");
    // wordDictionary.addWord("mad");

    // cout << wordDictionary.search("pad") << endl; // return False
    // cout << wordDictionary.search("bad") << endl; // return True
    // cout << wordDictionary.search(".ad") << endl; // return True
    // cout << wordDictionary.search("b..") << endl; // return True

    wordDictionary.addWord("a");
    wordDictionary.addWord("ab");

    cout << wordDictionary.search("") << endl;
    cout << wordDictionary.search("a") << endl;
    cout << wordDictionary.search("ab") << endl;
    cout << wordDictionary.search("a") << endl;
    cout << wordDictionary.search("a.") << endl;
    cout << wordDictionary.search(".a") << endl;
    cout << wordDictionary.search(".b") << endl;
    cout << wordDictionary.search("ab.") << endl;
    cout << wordDictionary.search(".") << endl;
    cout << wordDictionary.search("..") << endl;

    return 0;
}
