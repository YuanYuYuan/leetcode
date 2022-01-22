#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <cassert>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                dp[i][j] = -1;

        // can we zero the val by using elements after the index i
        const function<bool(size_t, int)> backtrace =
            [&](size_t idx, int val) -> bool {
                if (val == 0) return true;
                if (val < 0 || idx >= nums.size()) return false;
                if (dp[idx][val] != -1) return dp[idx][val];
                dp[idx][val] = backtrace(idx+1, val) || backtrace(idx+1, val - nums[idx]);
                return dp[idx][val];
            };
        return backtrace(0, sum / 2);
    }
private:
    const static size_t N = 201;
    const static size_t M = 10001;
    int dp[N][M];
};

int main() {
    vector<int> vec;
    Solution sol;

    vec = {1, 5, 11, 5};
    assert(sol.canPartition(vec) == true);
    vec = {1, 2, 3, 5};
    assert(sol.canPartition(vec) == false);
    vec = {1, 2, 5};
    assert(sol.canPartition(vec) == false);
    return 0;
}
