#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[slow];
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};

int main() {
    vector<int> nums = {3, 1, 3, 4, 2};
    Solution sol;
    cout << sol.findDuplicate(nums);
    return 0;
}
