#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int vmin = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++) {
            int dist = arr[i] - arr[i-1];
            vmin = min(vmin, dist);
            if (dist == 0) {
                break;
            }
        }
        vector<vector<int>> res = {};
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i-1] == vmin) {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};
