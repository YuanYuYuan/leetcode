#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (end <= i + nums[i]) end = i;
        }
        return end == 0;
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> nums = {2, 3, 1, 1, 4};
    // vector<int> nums = {5,9,3,2,1,0,2,3,3,1,0,0};
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << sol.canJump(nums) << endl;
    return 0;
}
