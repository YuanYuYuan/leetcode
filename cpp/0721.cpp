#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (auto acc: accounts) {
            for (int i = 2; i < acc.size(); i++) {
                graph[acc[i]].push_back(acc[i-1]);
                graph[acc[i-1]].push_back(acc[i]);
            }
        }

        for (auto acc: accounts) {
            if (!seen.count(acc[1])) {
                ans.push_back({acc[0]});
                dfs(acc[1]);
                sort(ans.back().begin()+1, ans.back().end());
            }
        }
        return ans;
    }

private:
    unordered_set<string> seen;
    unordered_map<string, vector<string>> graph;
    vector<vector<string>> ans;
    void dfs(string& node) {
        ans.back().push_back(node);
        seen.insert(node);
        for (auto neighbor: graph[node]) {
            if (!seen.count(neighbor)) {
                dfs(neighbor);
            }
        }
    }
};
