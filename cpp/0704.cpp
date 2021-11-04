#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {
            int k = (i + j) / 2;
            // [i, k)
            if (nums[k] > target) {
                j = k - 1;
            }
            // (k, j]
            else if (nums[k] < target) {
                i = k + 1;
            } else {
                return k;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 2;
    cout << sol.search(nums, target);
    return 0;
}

