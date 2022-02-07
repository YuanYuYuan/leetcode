#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        if (nums.size() == 1) return nums;
        unordered_map<int, int> counter;
        for (const auto& v: nums) counter[v]++;
        vector<int> res;
        for (const auto [v, n]: counter) {
            if (n == 1 && counter.count(v+1) == 0 && counter.count(v-1) == 0) {
                res.push_back(v);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {10, 6, 5, 8};
    // vector<int> vec = {1, 3, 5, 3};
    for (auto v: sol.findLonely(vec)) {
        cout << v << " ";
    }
    return 0;
}
