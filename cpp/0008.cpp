#include <string>
#include <iostream>
#include <unordered_map>
// #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int out = 0;
        int N = s.length();
        unordered_map<char, int> table = {
            {'0', 0},
            {'1', 1},
            {'2', 2},
            {'3', 3},
            {'4', 4},
            {'5', 5},
            {'6', 6},
            {'7', 7},
            {'8', 8},
            {'9', 9},
        };

        int i = 0;
        while (s[i] == ' ' &&  i < N) i++;
        if (i == N) return 0;

        bool pos = true;
        if (s[i] == '-') {
            pos = false;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        int limit = INT32_MAX / 10;
        int limit_res = INT32_MAX % 10;
        while (i < N) {
            if (table.find(s[i]) == table.end()) {
                break;
            } else {
                if (out > limit) {
                    return pos ? INT32_MAX : INT32_MIN;
                } else if (out == limit) {
                    if (pos && table[s[i]] >= limit_res) {
                        return INT32_MAX;
                    } else if (!pos && table[s[i]] > limit_res) {
                        return INT32_MIN;
                    }
                }
                out = out * 10 + table[s[i]];
            }
            i++;
        }
        return pos ? out : -out;
    }
};

int main() {
    Solution sol;
    cout << sol.myAtoi("42") << "\n";
    cout << sol.myAtoi("   -42") << "\n";
    cout << sol.myAtoi("4193 with words") << "\n";
    cout << sol.myAtoi("words and 987") << "\n";
    cout << sol.myAtoi("-91283472332") << "\n";
    cout << sol.myAtoi("2147483646") << "\n";
    return 0;
}
