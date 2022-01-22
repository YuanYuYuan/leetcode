#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>


using namespace std;


class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        const int N = s.size();
        vector<int> res{};
        for (int i = 0; i < N; i++) {
            int count = 0;
            int y = startPos[0];
            int x = startPos[1];
            for (int j = i; j < N; j++) {
                char c = s[j];
                if (c == 'R') {
                    x += 1;
                } else if ( c == 'L') {
                    x -= 1;
                } else if ( c == 'U') {
                    y -= 1;
                } else {
                    y += 1;
                }
                if (0 <= x && x < n && 0 <= y && y < n) {
                    count += 1;
                } else {
                    break;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};

int main() {
    Solution sol;
    // vector<int> startPos = {0, 1};
    // for (auto v: sol.executeInstructions(3, startPos, "RRDDLU")) {
    //     cout << v << " ";
    // }

    // vector<int> startPos = {1, 1};
    // for (auto v: sol.executeInstructions(2, startPos, "LURD")) {
    //     cout << v << " ";
    // }

    vector<int> startPos = {0, 0};
    for (auto v: sol.executeInstructions(1, startPos, "LRUD")) {
        cout << v << " ";
    }
    return 0;
}
