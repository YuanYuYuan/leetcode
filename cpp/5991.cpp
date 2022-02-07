#include <vector>
#include <iostream>

using namespace std;

// using two pointers is another good way

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (auto v: nums) {
            (v > 0 ? pos : neg).push_back(v);
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = (i % 2 == 0) ? pos[i / 2] : neg[i / 2];
        }
        return nums;
    }
};

int main() {
    vector<int> vec = {3,1,-2,-5,2,-4};
    // vector<int> vec = {-1, 1};
    for (auto v: Solution().rearrangeArray(vec)) {
        cout << v << " ";
    }
    return 0;
}
