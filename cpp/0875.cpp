#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>

using namespace std;

// additional sort make the program slower

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        const int N = piles.size();
        function<bool(int)> isFeasible = [&](int v) {
            int count = 0;
            for (const auto& p: piles) {
                count += (p / v) + ((p % v) > 0 ? 1 : 0);
                if (count > h) return false;
            }
            return count <= h;
        };

        int i = 1;
        int j = *max_element(piles.begin(), piles.end());
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (isFeasible(mid)) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }
    int slower(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        const int N = piles.size();
        function<bool(int)> isFeasible = [&](int v) {
            int count = 0;
            for (int i = N - 1; i >= 0; i--) {
                if (piles[i] <= v) {
                    count += i + 1;
                    break;
                }
                count += (piles[i] / v) + ((piles[i] % v) > 0 ? 1 : 0);
            }
            return count <= h;
        };

        int i = 1;
        int j = piles[N-1];
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (isFeasible(mid)) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }
};

int main() {
    vector<int> vec;
    Solution sol;

    vec = {3, 6, 7, 11};
    cout << Solution().minEatingSpeed(vec, 8) << endl;

    vec = {11, 23, 30, 20, 4};
    cout << Solution().minEatingSpeed(vec, 5) << endl;

    vec = {11, 23, 30, 20, 4};
    cout << Solution().minEatingSpeed(vec, 6) << endl;

    vec = {11};
    cout << Solution().minEatingSpeed(vec, 6) << endl;

    return 0;
}
