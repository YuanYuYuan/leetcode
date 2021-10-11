#include <iostream>

using namespace std;

class Solution {
public:
    // int rangeBitwiseAnd(int left, int right) {
    //     int count = 0;
    //     while (left != right) {
    //         left >>= 1;
    //         right >>= 1;
    //         count += 1;
    //     }
    //     return left << count;
    // }

    int rangeBitwiseAnd(int left, int right) {
        return left == right ? left : rangeBitwiseAnd(left >> 1, right >> 1) << 1;
    }
};

int main() {
    Solution sol;
    cout << sol.rangeBitwiseAnd(5, 7);
    return 0;
}
