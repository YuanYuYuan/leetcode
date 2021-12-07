#include <vector>
// #include "bits/stdc++.h"
#include <iostream>

using namespace std;

// vmax[i]: max value of product of subarray including a[i]
// vmin[i]: min value of product of subarray including a[i]
// nums: [2, 3, -2, 4, -1]
// vmax: 2, 6, -2, 4, 48
// vmin: 2, 3, -12, -48, -4
// prod: 2, 6, 6, 6, 48

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int vmax = nums[0];
        int vmin = nums[0];
        int prod = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int v = nums[i];
            int v1 = vmax * v;
            int v2 = vmin * v;
            vmax = max(v1, max(v2, v));
            vmin = min(v1, min(v2, v));
            prod = max(prod, vmax);
        }
        return prod;
    }
};

int main() {
    // vector<int> vec = {2, 3, -2, 4};
    vector<int> vec = {-2, 0, -1};
    Solution sol;
    cout << sol.maxProduct(vec);
    return 0;
}
