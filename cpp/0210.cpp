#include <vector>
#include <unordered_set>
#include <iostream>
#include <stack>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> graph;
        for (int i = 0; i < numCourses; i++) {
            graph.push_back({});
        }
        for (auto pair: prerequisites) {
            graph[pair[0]].insert(pair[1]);
        }

        // ----- This one failed -----
        // int visited[numCourses];
        // for (int i = 0; i < numCourses; i++) {
        //     visited[i] = 0;
        // }

        // ----- This one passed -----
        vector<int> visited(numCourses, 0);

        vector<int> res = {};
        bool cycleDetected = false;

        const static function<void(int i)> dfs = [&](int i) {
            if (visited[i] == 1) {
                cycleDetected = true;
                return;
            }
            if (visited[i] == 2) return;

            visited[i] = 1;
            for (auto j: graph[i]) {
                dfs(j);
            }
            visited[i] = 2;
            res.push_back(i);

        };

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        if (cycleDetected) {
            return {};
        } else {
            return res;
        }
    }
};

int main() {
    Solution sol;
    int numCourses;
    vector<vector<int>> prerequisites;

    numCourses = 2;
    prerequisites = {{0, 1}};
    for (auto v: sol.findOrder(numCourses, prerequisites)) {
        cout << v << " ";
    }
    cout << endl;

    numCourses = 4;
    prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    for (auto v: sol.findOrder(numCourses, prerequisites)) {
        cout << v << " ";
    }
    cout << endl;

    numCourses = 1;
    prerequisites = {};
    for (auto v: sol.findOrder(numCourses, prerequisites)) {
        cout << v << " ";
    }
    cout << endl;

    numCourses = 2;
    prerequisites = {{0, 1}, {1, 0}};
    for (auto v: sol.findOrder(numCourses, prerequisites)) {
        cout << v << " ";
    }
    cout << endl;
}
