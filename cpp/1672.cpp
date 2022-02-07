#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int vmax = 0;
        for (const auto& row: accounts) {
            vmax = max(vmax, accumulate(row.begin(), row.end(), 0));
        }
        return vmax;
    }
};
