#include <vector>
#include <iostream>

using namespace std;

// 0 0 1 1 1 1 2 3 3
// 0 0 1 1 x 1 2 3 3
// 0 0 1 1 x x 2 3 3
// 0 0 1 1 2 x x 3 3
// 0 0 1 1 2 3 3 x x

// 0 0 1 1 2 2 2 2 2 3 3
// 0 0 1 1 2 1 1 2 2 3 3
// 0 0 1 1 2 2 1 1 2 3 3

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 2) return N;
        int count = 2;
        for (int i = 2, j = 2; j < N; j++) {
            if (nums[j] > nums[i-2]) {
                nums[i] = nums[j];
                i += 1;
                count += 1;
            }
        }
        return count;
    }
};


int main() {
    vector<int> vec = {0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3};
    // for (auto v: vec) {
    //     cout << v << " ";
    // }
    // cout << endl;
    cout << Solution().removeDuplicates(vec) << endl;
    for (auto v: vec) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
