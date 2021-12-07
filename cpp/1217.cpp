#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int count[2] = {};
        for (auto p: position) count[p & 1]++;
        return min(count[0], count[1]);
    }

    // int minCostToMoveChips(vector<int>& position) {
    //     int numEven = accumulate(
    //         position.begin(),
    //         position.end(),
    //         0,
    //         [](int count, int v) -> int {
    //             return v % 2 == 0 ? count + 1 : count;
    //         }
    //     );
    //     return min(numEven, int(position.size() - numEven));
    // }
};

int main() {
    Solution sol;
    // vector<int> vec = {1, 2, 3};
    // vector<int> vec = {2, 2, 2, 3, 3};
    vector<int> vec = {1, 10000};
    cout << sol.minCostToMoveChips(vec) << endl;
    return 0;
}
