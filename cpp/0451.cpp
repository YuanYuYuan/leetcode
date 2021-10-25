// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.

// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
//
// "loveleetcode"
// "eeeeoollvtdc"

#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counter;
        for (char c: s) counter[c] += 1;
        vector<pair<char, int>> vec;
        for (const auto &[ch, freq]: counter) {
            vec.push_back(make_pair(ch, freq));
        }
        sort(vec.begin(), vec.end(), [](pair<char, int>a , pair<char, int> b) {
            return a.second > b.second;
        });

        string res;
        for (const auto &[ch, freq]: vec) {
            res += string(freq, ch);
        }
        return res;
    }
};

int main() {
    Solution sol;
    // string s = "tree";
    string s = "loveleetcode";
    cout << sol.frequencySort(s);
    return 0;
}
