#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int i = 0;
        int count = 0;
        while (i < nums.size()) {
            if (i+1 >= nums.size()) {
                count += 1;
                break;
            } else if (nums[i] == nums[i+1]) {
                count += 1;
                i += 1;
            } else {
                i += 2;
            }
        }
        return count;
    }
};

int main() {
    // vector<int> vec = {1, 1, 2, 3, 5};
    vector<int> vec = {1, 1, 2, 2, 3, 3};
    cout << Solution().minDeletion(vec) << endl;
    return 0;
}
