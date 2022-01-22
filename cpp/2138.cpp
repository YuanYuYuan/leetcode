#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res{};
        int i = 0;
        while (i < s.size()) {
            string word(k, fill);
            for (int j = 0; j < k && i < s.size(); j++) {
                word[j] = s[i++];
            }
            res.push_back(word);
        }
        return res;
    }
};

int main() {
    Solution sol;
    for (auto s: sol.divideString("abcdefghij", 3, 'x')) {
        cout << s << endl;
    }
    return 0;
}
