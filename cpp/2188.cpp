#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        const int M = 19;
        vector<int> noChange(M, INT_MAX);
        for (auto t: tires) {
            int f = t[0], r = t[1];
            noChange[1] = min(noChange[1], f);
            for (int i = 2, total = f, curr = f; i < M; i++) {
                curr *= r;
                total += curr;
                if (total > 2e5) break;
                noChange[i] = min(noChange[i], total);
            }
        }

        vector<int> dp(numLaps+1, INT_MAX);
        for (int i = 1; i <= numLaps; i++) {
            if (i < M) dp[i] = noChange[i];
            for (int j = 1; j <= i/2; j++) {
                dp[i] = min(dp[i], dp[j] + changeTime + dp[i-j]);
            }
        }
        return dp[numLaps];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> tires = {{2, 3}, {3, 4}};
    int changeTime = 5;
    int numLaps = 4;
    cout << sol.minimumFinishTime(tires, changeTime, numLaps) << endl;
    return 0;
}
