#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        counter[0] = 1;
        int res = 0;
        for (int preSum = 0, i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            res += counter[preSum - k];
            counter[preSum] += 1;
        }
        return res;
    }
};

int main() {
    vector<int> vec = {1, 2, 3};
    cout << Solution().subarraySum(vec, 3) << endl;
    return 0;
}
