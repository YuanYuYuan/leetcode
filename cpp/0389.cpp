#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (const auto& c: s + t) res ^= c;
        return res;
    }
};

int main() {
    cout << Solution().findTheDifference("abc", "abcd") << endl;
    return 0;
}
