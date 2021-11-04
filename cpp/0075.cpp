#include <vector>
#include <iostream>
#include <cassert>
#include <iostream>

using namespace std;

// Dutch partitiong problem

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int beg = 0;
        int mid = 0;
        int end = nums.size() - 1;
        while (mid <= end) {
            switch (nums[mid]) {
                case 0:
                    swap(nums[mid], nums[beg]) ;
                    beg++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[end]) ;
                    end--;
                    break;
                default:
                    break;
            }
        }
    }
};

int main() {
    // vector<int> vec = {1, 1, 1, 2, 0, 0, 1};
    // vector<int> vec = {2, 0, 2, 1, 1, 0};
    // vector<int> vec = {2, 0, 1};
    vector<int> vec = {1, 0, 0};
    Solution sol;
    sol.sortColors(vec);

    for (auto v: vec) {
        cout << v << " ";
    }
    cout << endl << endl;
    return 0;
}
