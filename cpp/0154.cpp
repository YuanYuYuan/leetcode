#include <vector>
#include <iostream>
using namespace std;


// nums[i] <= nums[mid] <= nums[j]: sorted, min inside
// nums[i] <= nums[mid] >  nums[j]: min inside (mid, j]
// nums[i] >  nums[mid] <= nums[j]: min inside (i, mid]
// nums[i] >  nums[mid] >  nums[j]: impossible

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[mid] > nums[j]) {
                i = mid + 1;
            } else if (nums[i] > nums[mid]) {
                j = mid;
                i++;
            } else {
                j--;
            }
        }
        return nums[i];
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {1, 3, 5};
    vector<int> nums = {1, 1, 1};
    // vector<int> nums = {2, 2, 0, 2};
    // vector<int> nums = {2, 2, 0, 1};
    // vector<int> nums = {2, 2, 3, 1};
    // vector<int> nums = {2, 1};
    cout << sol.findMin(nums);
    return 0;
}
