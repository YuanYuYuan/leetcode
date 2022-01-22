#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>

using namespace std;

/*
 * 0: 3
 * 1: 0
 * 2: 1
 * 3: 4
 * 4: 1
*/

/*
 * 0: [3, 1]
 * 1: [2, 4]
 * 2: [1]
 * 3: [0, 4]
 * 4: [3, 1]
*/

class Solution {
public:
    int maximumInvitations(vector<int>& outGraph) {
        const int N = outGraph.size();
        vector<vector<int>> inGraph(N);
        for (int i = 0; i < N; i++) {
            inGraph[outGraph[i]].push_back(i);
        }
        int maxCycle = 0;
        vector<int> status(N, 0);
        unordered_set<int> junctions;
        function<bool(int)> isCyclic = [&](int i) -> bool {
            int j = outGraph[i];
            if (depth[j] >= 1)
        }

        for (int i = 0; i < N; i++) {
            if (status[i] != 0) continue;
            if (outGraph[outGraph[i]] != i) continue;
        }
        for (int i = 0; i < N; i++) {
            if (outGraph[outGraph[i]] != i) continue;
        }
    }
};

int main() {
    Solution sol;
    vector<int> vec = {3, 0, 1, 4, 1};
    sol.maximumInvitations(vec);
    return 0;
}
