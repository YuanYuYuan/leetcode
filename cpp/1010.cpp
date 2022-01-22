#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>

using namespace std;

// [30, 20, 150, 100, 40]
// [30, 20, 30, 40, 40]
// [20, 30, 30, 40, 40]

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(60, 0);
        return accumulate(
            time.begin(),
            time.end(),
            0,
            [&](int total, int t) -> int {
                t %= 60;
                total += count[(60 - t) % 60];
                count[t] += 1;
                return total;
            }
        );
    }
};

int main() {
    Solution sol;
    vector<int> vec = {30, 20, 150, 100, 40};
    // vector<int> vec = {30, 30, 30};
    cout << sol.numPairsDivisibleBy60(vec) << endl;
    return 0;
}
