#include <vector>
#include <iostream>

using namespace std;

long long num2palindrome(long long num, bool isOdd) {
    long long rev = 0;
    long long numCopy = num;
    if (isOdd) num /= 10;
    long long mul = 1;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
        mul *= 10;
    }
    return rev + numCopy * mul;
}

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> res = {};
        if (intLength == 1) {
            for (auto v: queries) {
                if (v <= 9 && v >= 0) {
                    res.push_back(v);
                } else {
                    res.push_back(-1);
                }
            }
            return res;
        }

        bool isOdd = (intLength % 2 == 1);
        int len = intLength / 2 + intLength % 2;
        long long num = 1;
        for (int i = 0; i < len - 1; i++) {
            num *= 10;
        }
        long long lim = num * 10;
        for (auto v: queries) {
            v -= 1;
            if (num + v < lim) {
                res.push_back(num2palindrome(num + v, isOdd));
            } else {
                res.push_back(-1);
            }
        }

        return res;
    }
};

int main() {
    vector<int> queries = {1, 2, 3, 4, 5, 90};
    int intLength = 3;
    for (auto v: Solution().kthPalindrome(queries, intLength)) {
        cout << v << endl;
    }
    // cout << num2palindrome(123, false) << endl;
    return 0;
}
