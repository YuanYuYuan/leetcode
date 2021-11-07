#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // find the rightmost non-zero bit as the mask
        // this mask can separate v1 and v2
        // we need to set this as long since -INT_MIN is overflow in i32
        long int mask{};
        for (const auto v: nums) mask ^= v;
        mask &= -mask;

        int v1{}, v2{};
        for (const auto v: nums) {
            if (mask & v) {
                v1 ^= v;
            } else {
                v2 ^= v;
            }
        }
        return {v1, v2};
    }
};

#include <iostream>

int main() {
    Solution sol;
    vector<int> vec = {1, 2, 1, 3, 2, 5};
    for (const auto v: sol.singleNumber(vec)) {
        cout << v << " ";
    }
    return 0;
}
