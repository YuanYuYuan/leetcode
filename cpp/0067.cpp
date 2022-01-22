#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//  1111
//  1111
// 11110


class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry > 0) {
            if (i >= 0) carry += a[i--] - '0';
            if (j >= 0) carry += b[j--] - '0';
            res += (carry % 2 + '0');
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    // cout << sol.addBinary("11", "1") << endl;
    // cout << sol.addBinary("0", "1") << endl;
    // cout << sol.addBinary("1010", "1011") << endl;
    // cout << sol.addBinary("1111", "1111") << endl;
    cout << sol.addBinary("100", "110010") << endl;
    return 0;
}
