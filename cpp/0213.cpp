#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        auto scan = [&](int beg, int end) -> int {
            int inc = 0;
            int exc = 0;
            for (int i = beg; i < end; i++) {
                int tmp = inc;
                inc = max(inc, exc + nums[i]);
                exc = tmp;
            }
            return max(inc, exc);
        };
        int N = nums.size();
        return N == 1
            ? nums[0]
            : max(
                scan(0, N - 1),
                scan(1, N)
            );
    }
};

int main() {
    Solution sol;
    vector<int> vec = {2, 3, 2};
    cout << sol.rob(vec);
    return 0;
}
