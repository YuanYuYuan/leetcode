#include <vector>
#include <iostream>

using namespace std;

// 0 0 1 1 1 1 2 3 3
// 0 0 1 1 x 1 2 3 3
// 0 0 1 1 x x 2 3 3
// 0 0 1 1 2 x x 3 3
// 0 0 1 1 2 3 3 x x

// 0 0 1 1 1 1 2 2 2 3 3
// 0 0 1 1 2 1 1 2 2 3 3
// 0 0 1 1 2 2 1 1 2 3 3

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 2) return N;
        int count = 2;
        int last2 = nums[0];
        int last1 = nums[1];
        int j = 2;
        int i = 2;
        while (j < N) {
            if (nums[j] == last1 && nums[j] == last2) {
                while (j < N && nums[j] == last1) j++;
                if (j == N) break;
            }
            last2 = last1;
            last1 = nums[j];
            if (i != j) swap(nums[i], nums[j]);
            i++;
            j++;
            count++;
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
