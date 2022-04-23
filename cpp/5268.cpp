#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        for (auto v: nums1) set1.insert(v);
        for (auto v: nums2) set2.insert(v);
        vector<int> vec1, vec2;
        for (auto v: set1) if (set2.count(v) == 0) vec1.push_back(v);
        for (auto v: set2) if (set1.count(v) == 0) vec2.push_back(v);
        return {vec1, vec2};
    }
};
