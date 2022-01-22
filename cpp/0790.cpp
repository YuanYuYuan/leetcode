#include <iostream>
#include <cmath>

using namespace std;

const int MOD = pow(10, 9) + 7;

class Solution {
public:
    int numTilings(int n) {
        /* s[i]: num of tilings in the i-th squre
         * s[1] = 1
         * X
         * X
         *
         * s[2] = 2
         * X X
         * X X
         *
         * s[3] = 5
         * X X X      O X X   V V X    O X X
         * X X X   =  O X X + O O X  + O O X  * 2
         *
         * Formula: s[i] = s[i-1] + s[i-2] + t[i-2] * 2
         *
         * t[i]: num of tilings in the i-th trapezoid
         *
         * t[1] = 1
         * X
         * X X
         *
         * t[2] = 2
         * X X
         * X X X
         *
         * Formula: t[i] = t[i-1] + s[i-1]
         */
        if (n == 1) return 1;
        int s[n+1], t[n+1];
        s[1] = t[1] = 1;
        s[2] = 2;
        for (int i = 3; i <= n; i++) {
            // s[i] = s[i-1] + s[i-2] + t[i-2] * 2;
            s[i] = (s[i-1] + s[i-2]) % MOD;
            s[i] = (s[i] + t[i-2]) % MOD;
            s[i] = (s[i] + t[i-2]) % MOD;
            t[i-1] = (t[i-2] + s[i-2]) % MOD;
        }
        return s[n];
    }
};

int main() {
    Solution sol;
    cout << sol.numTilings(1000);
    return 0;
}
