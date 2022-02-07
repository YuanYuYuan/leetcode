#include <vector>
#include <iostream>
#include <tuple>

using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, cur = 0, idx = 0;
        for (int i = 0; i < gas.size(); i++) {
            int v = gas[i] - cost[i];
            total += v;
            cur += v;
            if (cur < 0) {
                cur = 0;
                idx = i+1;
            }
        }
        return (total >= 0) ? idx : -1;
    }
};

int main() {
    vector<int> gas, cost;
    Solution sol;
    gas = {1, 2, 3, 4, 5};
    cost = {3, 4, 5, 1, 2};
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    gas = {2, 3, 4};
    cost = {3, 4, 3};
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
