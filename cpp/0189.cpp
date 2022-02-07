#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// [1, 2, 3, 4, 5, 6, 7]
// [5, 6, 7, 1, 2, 3, 4]
// [5, 6, 7, 1, 2, 3, 4]
//
// [1, 2, 3, 4]
// [3, 2, 1, 4]

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        useReverse(nums, k);
        // cycleReplace(nums, k);
    }

    void useReverse(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    void cycleReplace(vector<int>& nums, int k) {
        const int N = nums.size();
        int counter = N;
        for (int start = 0; start < N; start++) {
            int pre = nums[start];
            int idx = (start + k) % N;
            while (idx != start) {
                int tmp = nums[idx];
                nums[idx] = pre;
                counter -= 1;
                pre = tmp;
                idx = (idx + k) % N;
            }
            nums[idx] = pre;
            counter -= 1;
            if (counter <= 0) break;
        }
    }
};

int main() {
    vector<int> vec;
    Solution sol;

    // vec = {1, 2, 3, 4};
    // sol.rotate(vec, 2);
    // for (const auto& v: vec) {
    //     cout << v << endl;
    // }

    vec = {1, 2, 3, 4, 5};
    sol.rotate(vec, 3);
    for (const auto& v: vec) {
        cout << v << endl;
    }
    return 0;
}
