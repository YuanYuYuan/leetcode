#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check by row
        for (int i = 0; i < 9; i++) {
            unordered_set<int> visited;
            for (int j = 0; j < 9; j++) {
                char v = board[i][j];
                if (v != '.') {
                    if (visited.find(v) != visited.end()) {
                        return false;
                    } else {
                        visited.insert(v);
                    }
                }
            }
        }

        // check by column
        for (int j = 0; j < 9; j++) {
            unordered_set<int> visited;
            for (int i = 0; i < 9; i++) {
                char v = board[i][j];
                if (v != '.') {
                    if (visited.find(v) != visited.end()) {
                        return false;
                    } else {
                        visited.insert(v);
                    }
                }
            }
        }

        // check by block
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                unordered_set<int> visited;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char v = board[x*3+i][y*3+j];
                        if (v != '.') {
                            if (visited.find(v) != visited.end()) {
                                return false;
                            } else {
                                visited.insert(v);
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};
