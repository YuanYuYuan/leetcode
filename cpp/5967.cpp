#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkString(string s) {
        const int N = s.size();
        int i = 0;
        while (i < N && s[i] != 'b') i++;
        while (i < N) {
            if (s[i] == 'a') return false;
            i++;
        };
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.checkString("a") << endl;
    cout << sol.checkString("b") << endl;
    cout << sol.checkString("aaabbb") << endl;
    cout << sol.checkString("abab") << endl;
    cout << sol.checkString("bbb") << endl;
    return 0;
}
