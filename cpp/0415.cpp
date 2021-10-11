#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int N1 = num1.length();
        int N2 = num2.length();
        if (N1 < N2) return addStrings(num2, num1);
        int carry = 0;

        // summation through the common parts
        for (int i1 = N1-1, i2 = N2-1; i2 >= 0; i1--, i2--) {
            int sum = char2digit(num1[i1]) + char2digit(num2[i2]) + carry;
            carry = sum / 10;
            num1[i1] = digit2char(sum % 10);
        }

        // go through the num1 with the possible carries
        for (int i = N1-N2-1; i >= 0 && carry != 0; i--) {
            int sum = char2digit(num1[i]) + carry;
            carry = sum / 10;
            num1[i] = digit2char(sum % 10);
        }

        // fianlly process the precending carry
        if (carry != 0) {
            num1.insert(0, 1, digit2char(carry));
        }

        return num1;
    }

private:
    char digit2char(int digit) {
        return (char)('0' + digit);
    }

    int char2digit(char c) {
        return c - '0';
    }
};

int main() {
    Solution sol;
    cout << sol.addStrings("123", "11") << "\n";
    cout << sol.addStrings("11", "123") << "\n";
    cout << sol.addStrings("456", "77") << "\n";
    cout << sol.addStrings("0", "0") << "\n";
    return 0;
}
