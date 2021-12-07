#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n, 1);
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                row[j] += row[j-1];
        return row[n-1];
    }
};

int main() {
    Solution sol;
    assert(sol.uniquePaths(3, 7) == 28);
    assert(sol.uniquePaths(7, 3) == 28);
    assert(sol.uniquePaths(3, 2) == 3);
    assert(sol.uniquePaths(3, 3) == 6);
    return 0;
}
