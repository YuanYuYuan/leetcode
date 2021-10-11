#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0') return 0;
        if (n == 1) return 1;
        int curr = 1;
        int prev = 1;
        for (int i = 1; i < n; i++) {
            int next = 0;
            // one letter
            if (s[i] != '0') {
                next += curr;
            }
            // two letters
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                next += prev;
            }
            prev = curr;
            curr = next;
        }
        return curr;
    }
};

int main() {
    Solution sol;
    cout << sol.numDecodings("12") << "\n";
    cout << sol.numDecodings("226") << "\n";
    cout << sol.numDecodings("0") << "\n";
    cout << sol.numDecodings("06") << "\n";
    return 0;
}
