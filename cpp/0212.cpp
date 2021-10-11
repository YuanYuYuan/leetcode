#include <vector>
#include <string>
#include <iostream>

using namespace std;

class TrieNode {
public:
    TrieNode* child[26] = {};
    string word = "";
};

class Trie {
public:
    TrieNode* root;
    Trie(const vector<string>& words) {
        root = new TrieNode();
        for (const string& w: words) {
            TrieNode* curr = this->root;
            for (char c: w) {
                int idx = c - 'a';
                if (!curr->child[idx]) {
                    curr->child[idx] = new TrieNode();
                }
                curr = curr->child[idx];
            }
            curr->word = w;
        }
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        int m = board.size();
        int n = board[0].size();
        vector<string> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, board, trie->root, res);
            }
        }
        return res;
    }

    // check the board[i][j] is valid and belongs to the trie
    void dfs(int i, int j, vector<vector<char>>& board, TrieNode* trie, vector<string>& res) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '#') return;
        TrieNode* t = trie->child[board[i][j] - 'a'];
        if (!t) return;
        if (t->word != "") {
            res.push_back(t->word);
            // change the word state to avoid the rework
            t->word = "";
        }
        const char c = board[i][j];
        board[i][j] = '#';
        dfs(i+1, j, board, t, res);
        dfs(i, j+1, board, t, res);
        dfs(i-1, j, board, t, res);
        dfs(i, j-1, board, t, res);
        board[i][j] = c;
    }
};

int main() {
    Solution sol;
    // vector<vector<char>> board = {
    //     {'o','a','a','n'},
    //     {'e','t','a','e'},
    //     {'i','h','k','r'},
    //     {'i','f','l','v'}
    // };
    // vector<string> words = {"oath","pea","eat","rain"};
    // vector<vector<char>> board = {{'a','b'},{'c','d'}};
    // vector<string> words = {"abcb"};
    vector<vector<char>> board = {
        {'o','a','b','n'},
        {'o','t','a','e'},
        {'a','h','k','r'},
        {'a','f','l','v'}
    };
    vector<string> words = {"oa","oaa"};
    for (auto w: sol.findWords(board, words)) {
        cout << w << endl;
    }
    return 0;
}
