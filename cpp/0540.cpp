#include <vector>
#include <iostream>
using namespace std;

// find the 1st index whose partner index holds a different value.
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[mid] == nums[mid^1]) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return nums[i];
    }
};

int main() {
    Solution sol;
    // vector<int> vec = {1, 2, 2};
    vector<int> vec ={1, 1, 2, 2, 3};
    // vector<int> vec = {2, 2, 3};
    // vector<int> vec = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << sol.singleNonDuplicate(vec);
    return 0;
}
