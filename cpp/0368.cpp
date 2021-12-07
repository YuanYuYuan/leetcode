#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        const int N = nums.size();
        if (nums.size() <= 1) {
            return nums;
        }
        sort(nums.begin(), nums.end());
        vector<int> ref(N, -1);
        vector<int> count(N, 1);
        int max_count = 0;
        int pointer = 0;
        for (int i = 1; i < nums.size(); i++) {
            int max_depth = 0;
            int max_ref = -1;
            for (int j = i-1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && count[j] > max_depth) {
                    max_depth = count[j];
                    max_ref = j;
                }
            }
            count[i] = max_depth + 1;
            ref[i] = max_ref;
            if (count[i] > max_count) {
                pointer = i;
                max_count = count[i];
            }
        }

        vector<int> res;
        while (pointer != -1) {
            res.push_back(nums[pointer]);
            pointer = ref[pointer];
        }
        return res;
    }
};

int main() {
    // vector<int> nums = {8, 1, 2, 4};
    vector<int> nums = {1, 2, 3};
    Solution sol;
    for (const auto v: sol.largestDivisibleSubset(nums)) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}

// nums:   1 3 6 9 27
// ref:    0 0 1 1  3
// count:  1 2 3 3  4
//
// 3 6 12 24
// 11 22 33
//  24 * 33
