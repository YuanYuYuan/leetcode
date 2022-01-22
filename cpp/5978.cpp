#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> start;
        for (auto word: startWords) {
            start.insert(wordToBit(word));
        }

        int count = 0;
        for (auto word: targetWords) {
            int val = wordToBit(word);
            for (auto c: word) {
                int candidate = val & ~(1 << (c - 'a'));
                if (start.find(candidate) != start.end()) {
                    count += 1;
                    break;
                }
            }
        }

        return count;
    }
private:
    int wordToBit(string& word) {
        int val = 0;
        for (auto c: word) {
            val |= (1 << (c - 'a'));
        }
        return val;
    }
};

int wordToBit(string word) {
    int val = 0;
    for (auto c: word) {
        val += (1 << (c - 'a'));
    }
    return val;
}

int main() {
    vector<string> startWords = {"ant","act","tack"};
    vector<string> targetWords = {"tack","act","acti"};

    // vector<string> startWords = {"ab","a"};
    // vector<string> targetWords = {"abc","abcd"};

    // vector<string> startWords = {"g","vf","ylpuk","nyf","gdj","j","fyqzg","sizec"};
    // vector<string> targetWords = {"r","am","jg","umhjo","fov","lujy","b","uz","y"};

    Solution sol;
    cout << sol.wordCount(startWords, targetWords) << endl;
    return 0;
}
