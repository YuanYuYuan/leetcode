#include <math.h>
#include <stdio.h>
using namespace std;


// Let f(k) = k * (k+1) / 2
// Goal: find k such that f(k-1) < n <= f(k)
// Solve k^2 + k - 2n = 0 => k = (-1 + sqrt(1 + 8n)) / 2

class Solution {
public:
    int arrangeCoins(int n) {
        return useBinarySearch(n);
        // return useQuadraticFormula(n);
    }

    int useBinarySearch(int n) {
        int i = 0;
        int j = n;
        // Note the overflow case
        long mid;
        while (i <= j) {
            mid = i + (j - i) / 2;
            long coins = (mid * (mid + 1)) / 2;
            if (coins == n) {
                return mid;
            } else if (coins < n) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        // case: i   j
        //         ^
        // i = mid, j = i + 1, f(mid) < n => i += 1
        return j;
    }

    int useQuadraticFormula(int n) {
        return floor((sqrt(1.0 + 8.0*n) - 1) / 2);
    }
};

int main() {
    Solution sol;
    printf("%d", sol.arrangeCoins(11));
    return 0;
}
