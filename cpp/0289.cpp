#include <vector>
#include <iostream>

using namespace std;

// 0 -> 0: 0
// 1 -> 1: 1
// 0 -> 1: 2
// 1 -> 0: 3

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int M = board.size();
        const int N = board[0].size();
        const vector<pair<int, int>> directions =  {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1}
        };
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int count = 0;
                for (auto [x, y]: directions) {
                    int I = i + x;
                    int J = j + y;
                    if (I < 0 || I >= M || J < 0 || J >= N) continue;
                    count += board[I][J] % 2;
                }
                if (board[i][j] == 1) {
                    if (count < 2 || count > 3) {
                        board[i][j] = 3;
                    }
                } else {
                    if (count == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }

        for (auto &row: board) {
            for (auto &elm: row) {
                if (elm == 2) {
                    elm = 1;
                } else if (elm == 3) {
                    elm = 0;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    Solution().gameOfLife(board);
    for (auto row: board) {
        for (auto elm: row) {
            cout << elm << " ";
        }
        cout << endl;
    }
    return 0;
}
