#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        const long long N = beans.size();
        map<long long, long long> counter;
        long long vmin = 0;
        for (auto v: beans) {
            counter[v] += 1;
            vmin += v;
        }

        long long pre_v = 0;
        long long pre_cnt = 0;
        long long right = N;
        long long curr = vmin;
        for (auto [v, cnt]: counter) {
            curr += pre_v * pre_cnt;
            curr -= (v - pre_v) * right;
            vmin = min(vmin, curr);
            pre_v = v;
            pre_cnt = cnt;
            right -= cnt;
        }
        return vmin;
    }
};


int main() {
    vector<int> vec = {4, 1, 6, 5};
    cout << Solution().minimumRemoval(vec) << endl;
    return 0;
}
