#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> idxOfElement;
        vector<int> res;
        for (int i = 0; i < nums2.size(); i++) {
            idxOfElement[nums2[i]] = i;
        }
        for (int i = 0; i < nums1.size(); i++) {
            res.push_back(-1);
        }
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = idxOfElement[nums1[i]] + 1; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    res[i] = nums2[j];
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    // vector<int> nums1 = {4,1,2};
    // vector<int> nums2 = {1,3,4,2};
    vector<int> nums1 = {2,4};
    vector<int> nums2 = {1,2,3,4};
    for (auto v: sol.nextGreaterElement(nums1, nums2)) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
