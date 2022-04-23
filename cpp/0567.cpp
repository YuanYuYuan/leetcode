#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        int counter[26]{};
        for (const auto& v: s1) counter[v - 'a'] += 1;
        int ammount = s1.size();
        for (int i = 0; i < s1.size(); i++) {
            int k = s2[i] - 'a';
            ammount -= (counter[k] >= 1) ? 1 : 0;
            counter[k] -= 1;
        }
        if (ammount == 0) return true;

        for (int i = s1.size(); i < s2.size(); i++) {
            int r = s2[i] - 'a';
            ammount -= (counter[r] >= 1) ? 1 : 0;
            counter[r] -= 1;
            int l = s2[i-s1.size()] - 'a';
            ammount += (counter[l] >= 0) ? 1 : 0;
            counter[l] += 1;
            if (ammount == 0) return true;
        }

        return false;
    }
};

int main() {
    cout << Solution().checkInclusion("ab", "eidbaooo") << endl;
    // cout << Solution().checkInclusion("ab", "aaasdfasdf") << endl;
    return 0;
}
