#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;


class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string numbers = to_string(n);
        const int N = numbers.size();
        const int D = digits.size();
        int res = 0;
        for (int i = 1; i < N; i++) {
            res += pow(D, i);
        }
        for (int i = 0; i < N; i++) {
            bool sameDigit = false;
            for (string s: digits) {
                if (s[0] < numbers[i]) {
                    res += pow(D, N - i - 1);
                } else if (s[0] == numbers[i]) {
                    sameDigit = true;
                }
            }
            if (!sameDigit) {
                return res;
            }
        }
        return res + 1;
    }
};

int main() {
    Solution sol;
    // vector<string> digits = {"1", "3", "5", "7"};
    // int n = 100;
    vector<string> digits = {"1", "4", "9"};
    int n = 1000000000;
    cout << sol.atMostNGivenDigitSet(digits, n);
}
