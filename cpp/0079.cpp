#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(i, j, 0, board, word))
                    return true;
        return false;
    }

private:
    bool dfs(int i, int j, int k, vector<vector<char>>& board, const string& word) {
        if (k == word.size()) return true;
        if (invalid(i, j, board)) return false;
        if (board[i][j] == word[k]) {
            char tmp = board[i][j];
            board[i][j] = '#';
            if (dfs(i+1, j, k+1, board, word)) return true;
            if (dfs(i-1, j, k+1, board, word)) return true;
            if (dfs(i, j+1, k+1, board, word)) return true;
            if (dfs(i, j-1, k+1, board, word)) return true;
            board[i][j] = tmp;
        }
        return false;
    }

    bool invalid(int i, int j, const vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        return i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#';
    }
};

int main() {
    using matrix = vector<vector<char>>;
    vector<pair<matrix, string>> list = {
        {
            {
                {'A','B','C','E'},
                {'S','F','C','S'},
                {'A','D','E','E'}
            },
            "ABCCED"
        },
        {
            {
                {'A','B','C','E'},
                {'S','F','C','S'},
                {'A','D','E','E'}
            },
            "SEE"
        },
        {
            {
                {'A','B','C','E'},
                {'S','F','C','S'},
                {'A','D','E','E'}
            },
            "ABCB"
        }
    };

    Solution sol;
    for (auto p: list) {
        cout << sol.exist(p.first, p.second);
    }
    return 0;
}
