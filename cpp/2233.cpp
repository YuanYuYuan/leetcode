#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const int M = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> que;
        for (auto v: nums) {
            que.push(v);
        }
        while (k--) {
            int v = que.top();
            que.pop();
            que.push(v+1);
        }
        long res = 1;
        while (que.size() > 0) {
            res *= que.top();
            res %= M;
            que.pop();
        }
        return res;
    }
};
