#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (auto v: nums) {
            vector<vector<int>> newVec = res;
            for (auto& vec: newVec) {
                vec.push_back(v);
            }
            res.insert(res.end(), newVec.begin(), newVec.end());
        }
        return res;
    }
};

int main() {
    vector<int> vec = {1, 2, 3};
    vector<vector<int>> powerSet = Solution().subsets(vec);
    for (auto row: powerSet) {
        for (auto v: row) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
