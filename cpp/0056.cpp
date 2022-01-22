#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res = {intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {
        {8, 10},
        {2, 6},
        {1, 3},
        {15, 18}
    };
    // vector<vector<int>> intervals = {
    //     {4, 5},
    //     {1, 4}
    // };
    for (auto intv: sol.merge(intervals)) {
        cout << intv[0] << ", " << intv[1] << endl;
    }
    return 0;
}
