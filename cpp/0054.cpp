#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int U = 0, L = 0;
        int D = matrix.size() - 1;
        int R = matrix[0].size() - 1;
        vector<int> res;

        while (L <= R && U <= D) {
            // go right
            for (int i = U, j = L; j <= R; j++) {
                res.push_back(matrix[i][j]);
            }
            U++;

            // go down
            for (int i = U, j = R; i <= D; i++) {
                res.push_back(matrix[i][j]);
            }
            R--;

            if (L > R || U > D) {
                break;
            }

            // go left
            for (int i = D, j = R; j >= L; j--) {
                res.push_back(matrix[i][j]);
            }
            D--;

            // go up
            for (int i = D, j = L; i >= U; i--) {
                res.push_back(matrix[i][j]);
            }
            L++;
        }
        return res;
    }
};

int main() {
    // vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution sol;
    vector<int> res = sol.spiralOrder(matrix);
    for (auto v: res) {
        cout << v << ", ";
    }
}
