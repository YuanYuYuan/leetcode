#include <vector>
#include <unordered_map>
#include <iostream>
#include <numeric>

using namespace std;


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> preSumIdx;
        preSumIdx[0] = -1;
        int res;
        for (int i = 0, preSum = 0; i < nums.size(); i++) {
            preSum += nums[i] ? 1 : -1;
            if (preSumIdx.count(preSum)) {
                res = max(res, i - preSumIdx[preSum]);
            } else {
                preSumIdx[preSum] = i;
            }
        }
        return res;
    }
};

int main() {
    vector<int> vec = {0, 0, 0, 1, 1, 1};
    // vector<int> vec = {0, 0, 1, 0, 0, 0, 1, 1};
    cout << Solution().findMaxLength(vec) << endl;
    return 0;
}
