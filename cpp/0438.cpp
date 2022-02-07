#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int M = s.size();
        const int N = p.size();
        if (M < N) return {};

        int remain[26]{};
        for (auto c: p) remain[c - 'a'] += 1;

        int n_remain = N;
        for (int i = 0; i < N; i++) {
            if (remain[s[i] - 'a']-- >= 1) n_remain -= 1;
        }

        vector<int> res;
        if (n_remain == 0) res.push_back(0);

        for (int i = 0, j = N; j < M; i++, j++) {
            if (remain[s[i] - 'a']++ >= 0) n_remain += 1;
            if (remain[s[j] - 'a']-- >= 1) n_remain -= 1;
            if (n_remain == 0) res.push_back(i + 1);
        }

        return res;
    }
};

int main() {
    for (auto v: Solution().findAnagrams("cbaebabacd", "abc")) {
    // for (auto v: Solution().findAnagrams("abab", "ab")) {
        cout << v << endl;
    }
    return 0;
}
