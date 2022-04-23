#include <vector>
#include <iostream>

using namespace std;

// 2: 1 1 1 = 3
// 3: 2 2 2 1 1 = 8
// 4: 3 3 3 2 2 1 1 = 15
// 5: 4 4 4 3 3 2 2 1 1 = 24
// 6: 5 5 5 4 4 3 3 2 2 1 1 = 24
// 7: 6 6 6 5 5 4 4 3 3 2 2 1 1 = 24
// 8: 7 7 7 6 6 5 5 4 4 3 3 2 2 1 1 = 24

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));

        for (int j = 0; j < n; j++) mat[0][j] = j + 1;

        const pair<int, int> dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int i = 0, j = n - 1, v = n+1, nSteps = n-1, d = 1; nSteps > 0; nSteps--) {
            for (int k = 0; k < 2; k++) {
                int c = nSteps;
                while (c--) {
                    auto [di, dj] = dir[d];
                    i += di;
                    j += dj;
                    mat[i][j] = v++;
                }
                d = (d + 1) % 4;
            }
        }
        return mat;
    }
};

int main() {
    for (auto row: Solution().generateMatrix(3)) {
        for (auto elm: row) {
            cout << elm << " ";
        }
        cout << endl;
    }
    return 0;
}


