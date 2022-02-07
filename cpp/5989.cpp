#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        int count = N;
        for (int i = 0; i < N; i++) {
            if (nums[i] == nums[0]) {
                count -= 1;
            } else {
                break;
            }
        }
        if (count < 2) return 0;

        for (int j = N - 1; j >= 0; j--) {
            if (nums[j] == nums[N - 1]) {
                count -= 1;
            } else {
                break;
            }
        }
        return count;
    }
};

int main() {
    vector<int> vec;
    vec = {2, 2, 2, 2};
    cout << Solution().countElements(vec) << endl;
    return 0;
}
