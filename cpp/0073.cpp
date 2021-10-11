#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_row = false;
        bool first_col = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                first_col = true;
                break;
            }
        }

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                first_row = true;
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (first_col) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (first_row) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};


int main() {
    // vector<vector<int>> m = {
    //     {1, 1, 1},
    //     {1, 0, 1},
    //     {1, 1, 1}
    // };
    vector<vector<int>> m = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    Solution sol;
    sol.setZeroes(m);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++)
            cout << m[i][j];
        cout << "\n";
    }
    return 0;
}
