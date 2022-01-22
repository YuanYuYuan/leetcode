#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int M = matrix.size();
        const int N = matrix[0].size();
        int maxSquareLength = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int squareLength = min(M - i, N - j);
                if (squareLength <= maxSquareLength) {
                    continue;
                }

                for (int len = 1; len <= squareLength && checkBoundary(matrix, i, j, len); len++) {
                    maxSquareLength = max(maxSquareLength, len);
                }
            }
        }
        return maxSquareLength * maxSquareLength;
    }
private:
    bool checkBoundary(vector<vector<char>>& matrix, int row, int col, int squareLength) {
        int I = row + squareLength - 1;
        int J = col + squareLength - 1;
        int prod = char2int(matrix[I][J]);
        if (prod == 0) return false;
        for (int i = row; i < I; i++) {
            prod *= char2int(matrix[i][J]);
            if (prod == 0) return false;
        }
        for (int j = col; j < J; j++) {
            prod *= char2int(matrix[I][j]);
            if (prod == 0) return false;
        }
        return true;
    }

    int char2int(char v) {
        return v == '1' ? 1 : 0;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> matrix;
    matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << sol.maximalSquare(matrix) << endl;

    matrix = {{'0','1'},{'1','0'}};
    cout << sol.maximalSquare(matrix) << endl;

    matrix = {{'0'}};
    cout << sol.maximalSquare(matrix);
    return 0;
}
