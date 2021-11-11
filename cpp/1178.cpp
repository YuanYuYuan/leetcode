#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> mask_freq{};
        vector<int> masks{};
        for (const auto word: words) {
            mask_freq[getMask(word)] += 1;
        }

        vector<int> res{};
        for (const auto puz: puzzles) {
            int summ = 0;
            int mask = getMask(puz);
            int submask = mask;
            int first = 1 << (puz[0] - 'a');
            while (submask) {
                if (first & submask) {
                    summ += mask_freq[submask];
                }
                submask = (submask - 1) & mask;
            }
            res.push_back(summ);
        }
        return res;
    }
private:
    int getMask(string word) {
        int mask = 0;
        for (const auto w: word) {
            mask |= 1 << (w - 'a');
        }
        return mask;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"aaaa","asas","able","ability","actt","actor","access"};
    vector<string> puzzles = {
        "aboveyz",
        "abrodyz",
        "abslute",
        "absoryz",
        "actresz",
        "gaswxyz"
    };
    for (auto v: sol.findNumOfValidWords(words, puzzles)) {
        cout << v << endl;
    }
    return 0;
}
