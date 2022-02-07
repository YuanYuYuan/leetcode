#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int held = prices[0];
        int vmax = 0;
        for (int i = 1; i < prices.size(); i++) {
            vmax = max(vmax, prices[i] - held);
            held = min(held, prices[i]);
        }
        return vmax;
    }
};
