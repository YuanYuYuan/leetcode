#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int grid[1000][1000]{};
        const int M = artifacts.size();
        vector<int> counter(M, 0);
        int res = 0;
        int idx = 1;
        for (auto art: artifacts) {
            for (int i = art[0]; i <= art[2]; i++) {
                for (int j = art[1]; j <= art[3]; j++) {
                    grid[i][j] = idx;
                }
            }
            counter[idx - 1] = (art[2] - art[0] + 1) * (art[3] - art[1] + 1);
            idx += 1;
        }

        for (auto d: dig) {
            int idx = grid[d[0]][d[1]];
            if (idx != 0) {
                counter[idx - 1] -= 1;
                if (counter[idx - 1] == 0) {
                    res += 1;
                }
            }
        }
        return res;
    }
};

int main() {
    // int n = 2;
    // vector<vector<int>> artifacts = {{0,0,0,0},{0,1,1,1}};
    // vector<vector<int>> dig = {{0,0},{0,1},{1,1}};
    int n = 6;
    vector<vector<int>> artifacts = {{0,2,0,5},{0,1,1,1},{3,0,3,3},{4,4,4,4},{2,1,2,4}};
    vector<vector<int>> dig = {{0,2},{0,3},{0,4},{2,0},{2,1},{2,2},{2,5},{3,0},{3,1},{3,3},{3,4},{4,0},{4,3},{4,5},{5,0},{5,1},{5,2},{5,4},{5,5}};
    cout << Solution().digArtifacts(n, artifacts, dig) << endl;
    return 0;
}
