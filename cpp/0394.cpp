#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
    }

private:
    bool isNumeric(char c) {
        int v = c - '0';
        return 0 <= v && v <= 9;
    }

    bool isLetter(char c) {
        int v = c - 'a';
        return 0 <= v && v < 26;
    }

    string repeatString(string s, int times) {
        string out = "";
        for (int i = 0; i < times; i++) {
            out += s;
        }
        return out;
    }
};

int main() {
    Solution sol;
    // cout << sol.decodeString("3[a]2[bc]") << endl;
    assert(sol.decodeString("3[a]2[bc]") == "aaabcbc");
    assert(sol.decodeString("3[a2[c]]") == "accaccacc");
    assert(sol.decodeString("abc3[cd]xyz") == "abccdcdcdxyz");
    return 0;
}
