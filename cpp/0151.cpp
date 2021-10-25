#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<pair<int, int>> indices;
        int len = 0;
        for (int i = 0; i < s.size(); ) {
            while (s[i] == ' ' && i < s.size()) i++;
            if (i >= s.size()) break;
            int j = i+1;
            while (s[j] != ' ' && j < s.size()) j++;
            pair<int, int> p(i, j);
            indices.push_back(p);
            len += j - i;
            i = j + 1;
        }
        len += indices.size() - 1;
        string res(len, ' ');
        // for (auto p: indices) {
        //     cout << p.first << ", " << p.second << endl;
        // }
        int i = 0;
        int j = len - 1;
        for (int k = 0; k < indices.size() / 2 + indices.size() % 2; k++) {
            pair<int, int> left = indices[indices.size() - k - 1];
            pair<int, int> right = indices[k];
            for (int idx = left.first; idx < left.second; idx++) {
                res[i] = s[idx];
                i++;
            }
            if (i >= j) break;
            if (i < len) {
                res[i] = ' ';
                i++;
            }
            for (int idx = right.second - 1; idx >= right.first; idx--) {
                res[j] = s[idx];
                j--;
            }
            if (j >= 0) {
                res[j] = ' ';
                j--;
            }
        }

        // string out(res);
        // cout << out.size();
        return res;
    }
};

int main() {
    Solution sol;
    // string s =  " the sky is blue  ";
    // string s = "  hello world  ";
    // string s = "a good   example";
    // string s = "  Bob    Loves  Alice   ";
    string s = "Alice does not even like bob";
    cout << sol.reverseWords(s);
    return 0;
}

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"

// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.

// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

// Example 4:

// Input: s = "  Bob    Loves  Alice   "
// Output: "Alice Loves Bob"

// Example 5:

// Input: s = "Alice does not even like bob"
// Output: "bob like even not does Alice"
