#include <vector>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
        const vector<int> movements = {-1, 0, 1};

        vector<vector<vector<int>>> cache(M, vector<vector<int>>(N, vector<int>(N, -1)));

        // y:  layers of two robots
        // x1: x position of the 1st robot
        // x2: x position of the 2nd robot
        function<int(int, int, int)> dp = [&](int y, int x1, int x2) {
            if (x1 < 0 || x1 >= N || x2 < 0 || x2 >= N || y >= M) return 0;
            int& res = cache[y][x1][x2];
            if (res != -1) return res;
            const int cur = grid[y][x1] + (x1 != x2 ? grid[y][x2] : 0);
            for (auto m1: movements) {
                for (auto m2: movements) {
                    res = max(res, dp(y+1, x1+m1, x2+m2)) ;
                }
            }
            res = cur + max(0, res);
            return res;
        };

        return dp(0, 0, N-1);
    }
};

int main() {
    vector<vector<int>> grid = {
        {3,1,1},
        {2,5,1},
        {1,5,5},
        {2,1,1}
    };
    Solution sol;
    cout << sol.cherryPickup(grid) << endl;
    return 0;
}
