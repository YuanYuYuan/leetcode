#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // // O(n) space
    // int maxProfit(vector<int>& prices) {
    //     int N = prices.size();
    //     int rest[N], hold[N], sold[N];
    //     rest[0] = 0;
    //     sold[0] = 0;
    //     hold[0] = -prices[0];
    //     for (int i = 1; i < N; i++) {
    //         rest[i] = max(rest[i-1], sold[i-1]);
    //         hold[i] = max(rest[i-1] - prices[i], hold[i-1]);
    //         sold[i] = hold[i-1] + prices[i];
    //     }
    //     return max(rest[N-1], sold[N-1]);
    // }

    // O(1) space
    int maxProfit(vector<int>& prices) {
        int rest = 0;
        int sold = 0;
        int hold = -prices[0];
        int prev_sold;
        for (auto p: prices) {
            prev_sold = sold;
            sold = hold + p;
            hold = max(hold, rest - p);
            rest = max(rest, prev_sold);
        }
        return max(rest, sold);
    }
};

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};
    Solution sol;
    cout << sol.maxProfit(prices);
    return 0;
}
