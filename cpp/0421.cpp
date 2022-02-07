#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            ans <<= 1;
            unordered_set<int> prefixes;
            for (const auto& v: nums) {
                prefixes.insert(v >> i);
            }
            for (auto p: prefixes) {
                if (prefixes.count(p ^ ans ^ 1) > 0) {
                    ans += 1;
                    break;
                }
            }

        }
        // int ans = 0, mask = 0;
        // for (int i = 31; i >= 0; i--) {
        //     unordered_set<int> prefixes;
        //     mask |= 1 << i;
        //     for (const auto& v: nums) {
        //         prefixes.insert(mask & v);
        //     }
        //     int start = ans | 1 << i;
        //     for (auto p: prefixes) {
        //         if (prefixes.count(p ^ start) > 0) {
        //             ans = start;
        //             break;
        //         }
        //     }
        // }
        return ans;
    }
};

int main() {
    vector<int> vec = {3, 10, 5, 25, 2, 8};
    cout << Solution().findMaximumXOR(vec) << endl;
    return 0;
}
