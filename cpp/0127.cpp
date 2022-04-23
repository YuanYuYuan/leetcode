#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        bool hasEndWord = false;
        for (auto w: wordList) {
            if (w == endWord) hasEndWord = true;
            set.insert(w);
        }
        if (!hasEndWord) return 0;

        queue<string> myQueue;
        myQueue.push(beginWord);
        for (int level = 2; !myQueue.empty(); level++) {
            for (int i = myQueue.size() - 1; i >= 0; i--) {
                string word = myQueue.front();
                myQueue.pop();
                string neighbor = word;
                for (int j = 0; j < word.size(); j++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == word[j]) continue;
                        neighbor[j] = c;
                        if (neighbor == endWord) return level;
                        if (set.count(neighbor)) {
                            myQueue.push(neighbor);
                            set.erase(neighbor);
                        }
                    }
                    neighbor[j] = word[j];
                }
            }
        }
        return 0;
    }
};

int main() {
    string beginWord, endWord;
    vector<string> wordList;
    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    // wordList = {"hot","dot","dog","lot","log"};
    cout << Solution().ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
