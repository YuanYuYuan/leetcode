#include <vector>

using namespace std;


class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        const int M = matrix.size();
        const int N = matrix[0].size();

        for (int i{}; i < M; i++) {
            int by_row = 0;
            for (int j{}; j < N; j++) {
                by_row ^= ((j+1) ^ matrix[i][j]);
            }
            if (by_row != 0) return false;
        }

        for (int j{}; j < N; j++) {
            int by_col = 0;
            for (int i{}; i < M; i++) {
                by_col ^= ((i+1) ^ matrix[i][j]);
            }
            if (by_col != 0) return false;
        }

        return true;
    }
};
