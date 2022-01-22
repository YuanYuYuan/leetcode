#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        char prev = s[0];
        int maxSum = 1;
        int curSum = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == prev) {
                curSum += 1;
                if (curSum > maxSum) maxSum = curSum;
            } else {
                curSum = 1;
                prev = s[i];
            }
        }
        return maxSum;
    }
};

int main() {
    Solution sol;
    assert(sol.maxPower("leetcode") == 2);
    assert(sol.maxPower("abbcccddddeeeeedcba") == 5);
    assert(sol.maxPower("triplepillooooow") == 5);
    assert(sol.maxPower("hooraaaaaaaaaaay") == 11);
    assert(sol.maxPower("tourist") == 1);
    return 0;
}
