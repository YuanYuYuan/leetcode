#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long lcm = a * b / gcd(a, b);
        long lo = min(a, b);
        long hi = n * lcm;
        while (lo < hi) {
            long mi = (lo + hi) / 2;
            if (mi / a + mi / b - mi / lcm < n) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return lo % (long)(1e9 + 7);
    }
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

int main() {
    Solution sol;
    // cout << sol.nthMagicalNumber(1, 2, 3);
    cout << sol.nthMagicalNumber(4, 2, 3);
    return 0;
}
