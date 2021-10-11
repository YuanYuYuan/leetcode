#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int k = (i + j) / 2;
            if (nums[j] > nums[k]) {
                j = k;
            } else {
                i = k+1;
            }
        }
        return nums[i];
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    nums = {2, 1};
    cout << sol.findMin(nums) << endl;
    nums = {3, 4, 5, 1, 2};
    cout << sol.findMin(nums) << endl;
    nums = {4, 5, 6, 7, 0, 1, 2};
    cout << sol.findMin(nums) << endl;
    nums = {11, 13, 15, 17};
    cout << sol.findMin(nums) << endl;
}
