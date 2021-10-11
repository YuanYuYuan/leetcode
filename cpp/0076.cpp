#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        if (t.size() == 1) return (s.find(t[0]) == string::npos) ? "" : t;
        vector<int> need(128, 0);
        for (auto& c: t) need[c]++;
        int I = 0;
        int min_len = INT_MAX;
        int remain = t.size();
        for (int i = 0, j = 0; j < s.size(); j++) {
            remain -= need[s[j]] > 0 ? 1 : 0;
            need[s[j]]--;
            if (remain == 0) {
                while (i <= j) {
                    if (need[s[i]] >= 0) break;
                    need[s[i]]++;
                    i++;
                }
                int cur_len = j-i+1;
                if (min_len > cur_len) {
                    min_len = cur_len;
                    I = i;
                }
            }
        }
        return min_len == INT_MAX ? "" : s.substr(I, min_len);
    }
};


int main() {
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << "\n";
    cout << sol.minWindow("a", "a") << "\n";
    cout << sol.minWindow("a", "aa") << "\n";
}
