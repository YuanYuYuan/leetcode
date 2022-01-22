#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n, 0);
        vector<int> outDegree(n, 0);
        for (auto t: trust) {
            outDegree[t[0] - 1] += 1;
            inDegree[t[1] - 1] += 1;
        }
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == n-1 && outDegree[i] == 0) return i + 1;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    // vector<vector<int>> vec = {{1, 2}};
    // cout << sol.findJudge(2, vec) << endl;
    // vector<vector<int>> vec = {{1, 3}, {2, 3}};
    // cout << sol.findJudge(3, vec) << endl;
    vector<vector<int>> vec = {{1, 3}, {2, 3}, {3, 1}};
    cout << sol.findJudge(3, vec) << endl;
    return 0;
}
