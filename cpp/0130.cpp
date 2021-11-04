#include <vector>
#include <iostream>
#include <functional>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int M = board.size();
        const int N = board[0].size();

        static const function<void(int, int)> traverse = [&](const int i, const int j) {
            if (0 <= i && i < M && 0 <= j && j < N && board[i][j] == 'O') {
                board[i][j] = '#';
                traverse(i+1, j);
                traverse(i-1, j);
                traverse(i, j+1);
                traverse(i, j-1);
            }
        };

        for (int i = 0; i < M; i++) {
            traverse(i, 0);
            traverse(i, N-1);
        }

        for (int j = 1; j < N - 1; j++) {
            traverse(0, j);
            traverse(M-1, j);
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }


};

int main() {
    Solution sol;
    // vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    // vector<vector<char>> board = {
    //     {'X','O','O','X','X','X','O','X','O','O'},
    //     {'X','O','X','X','X','X','X','X','X','X'},
    //     {'X','X','X','X','O','X','X','X','X','X'},
    //     {'X','O','X','X','X','O','X','X','X','O'},
    //     {'O','X','X','X','O','X','O','X','O','X'},
    //     {'X','X','O','X','X','O','O','X','X','X'},
    //     {'O','X','X','O','O','X','O','X','X','O'},
    //     {'O','X','X','X','X','X','O','X','X','X'},
    //     {'X','O','O','X','X','O','X','X','O','O'},
    //     {'X','X','X','O','O','X','O','X','X','O'}
    // };

    vector<vector<char>> board = {
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','X','X','X','X','O','O','O','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','O','O','O','X','O','X','O','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','O','X','O','X','O','X','O','O','O','X','X','X','X','X','X'},
        {'X','X','X','X','X','O','X','O','O','O','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
    };

    for (auto row: board) {
        for (auto v: row) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    // sol.display();
    sol.solve(board);
    // sol.display();
    for (auto row: board) {
        for (auto v: row) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
