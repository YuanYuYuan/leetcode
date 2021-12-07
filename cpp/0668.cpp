#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 0;
        int hi = m*n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int count = countLessOrEqual(m, n, mid);
            if (count < k) {
                lo = mid + 1;
            } else {
                return mid;
            }
        }
        return lo;
    }

private:
    int countLessOrEqual(int m, int n, int target) {
        int count = 0;
        for (int row = 0; row < m; row++) {
            count += min(target / (row+1), n);
        }
        return count;
    }
};

int main() {
    Solution sol;
    cout << sol.findKthNumber(3, 3, 5) << endl;
    cout << sol.findKthNumber(2, 3, 6) << endl;
    return 0;
}
