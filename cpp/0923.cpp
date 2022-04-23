#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>


using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MODULO = 1e9 + 7;

        unordered_map<int, long> counter{};
        for (auto v: arr) {
            counter[v] += 1;
        }

        long res{};

        for (auto [v1, c1]: counter) {
            for (auto [v2, c2]: counter) {
                int v3 = target - v1 - v2;
                if (!counter.count(v3)) continue;
                long c3 = counter[v3];
                if (v1 == v2 && v1 == v3) {
                    res += c1 * (c1-1) * (c1-2) / 6;
                } else if (v1 == v2 && v1 != v3) {
                    res += c1 * (c1-1) / 2 * c3;
                } else if (v1 < v2 && v2 < v3) {
                    res += c1 * c2 * c3;
                }
            }
        }
        return res % MODULO;
    }
};

int main() {
    // vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    // int target = 8;
    vector<int> arr = {1, 1, 2, 2, 2, 2};
    int target = 5;
    cout << Solution().threeSumMulti(arr, target) << endl;
    return 0;
}
