#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int stringToNum(string s) {
    if (s == "") return 1;
    return stoi(s);
}


class Solution {
public:
    string minimizeResult(string expression) {
        size_t end = expression.find('+', 0);
        string left = expression.substr(0, end);
        string right = expression.substr(end+1);
        int vmin = INT32_MAX;
        int leftMul{}, leftAdd{}, rightAdd{}, rightMul{};
        string res;
        for (int i = 0; i < left.size(); i++) {
            leftMul = stringToNum(left.substr(0, i));
            leftAdd = stringToNum(left.substr(i));
            for (int j = 0; j < right.size(); j++) {
                rightAdd = stringToNum(right.substr(0, j+1));
                rightMul = stringToNum(right.substr(j+1));
                int val = leftMul * (leftAdd + rightAdd) * rightMul;
                if (val < vmin) {
                    vmin = val;
                    res = left.substr(0, i)
                        + "(" + left.substr(i) + "+" + right.substr(0, j+1) + ")"
                        + right.substr(j+1);
                    if (vmin == 0) return res;
                }
            }
        }
        return res;
    }
};


int main() {
    cout << Solution().minimizeResult("247+38") << endl;
    cout << Solution().minimizeResult("12+34") << endl;
    cout << Solution().minimizeResult("999+999") << endl;
    return 0;
}
