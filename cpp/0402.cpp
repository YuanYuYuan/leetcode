#include <string>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        const int N = num.size();
        if (k >= N) return "0";
        if (k == 0) return num;
        stack<char> stk;
        for (auto c: num) {
            if (stk.empty()) {
                if (c != '0') {
                    stk.push(c);
                }
            } else {
                while (k > 0 && !stk.empty() && stk.top() > c) {
                    k -= 1;
                    stk.pop();
                }
                if (c == '0' && stk.empty()) {
                    continue;
                }
                stk.push(c);
            }
        }
        string res{};
        while (!stk.empty()) {
            if (k > 0) {
                k -= 1;
            } else {
                res.push_back(stk.top());
            }
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res == "" ? "0" : res;

    }
};


int main() {
    // cout << Solution().removeKdigits("1432219", 3) << endl;
    // cout << Solution().removeKdigits("10200", 1) << endl;
    // cout << Solution().removeKdigits("10", 1) << endl;
    // cout << Solution().removeKdigits("221", 1) << endl;
    // cout << Solution().removeKdigits("112", 1) << endl;
    cout << Solution().removeKdigits("5337", 2) << endl;
    cout << Solution().removeKdigits("100002", 4) << endl;
    // cout << Solution().removeKdigits("10001", 1) << endl;
    return 0;
}
