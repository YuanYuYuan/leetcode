#include <vector>
#include <unordered_set>
#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

/*
 * 0: 1
 * 1: 0 2 3
 * 2: 1
 * 3: 1
 * */

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<unordered_set<int>> graph(n);
        for (const auto& e: edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }

        vector<int> leaves, degrees(n);
        for (int i = 0; i < n; i++) {
            degrees[i] = graph[i].size();
            if (degrees[i] == 1) {
                leaves.push_back(i);
            }
        }

        int numNodes = n;
        while (numNodes > 2) {
            vector<int> newLeaves;
            for (const auto& leaf: leaves) {
                for (const auto& adj: graph[leaf]) {
                    degrees[adj] -= 1;
                    if (degrees[adj] == 1) {
                        newLeaves.push_back(adj);
                    }
                }
            }
            numNodes -= leaves.size();
            leaves = move(newLeaves);
        }

        return leaves;
    }
};

class FindLongestPath {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        graph = vector<unordered_set<int>>(n);
        for (auto e: edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }

        // find the farthest node from the node 0
        int farthest = findLongestPath(0, -1)[0];

        // use this node to find the longest path inside the graph
        vector<int> longestPath = findLongestPath(farthest, -1);

        // the nodes with minimal height should locate in the middle of the longest path
        int idx = longestPath.size() / 2;
        if (longestPath.size() % 2 == 0) {
            return {
                longestPath[idx-1],
                longestPath[idx]
            };
        } else {
            return {longestPath[idx]};
        }
    }
private:
    vector<unordered_set<int>> graph;
    vector<int> findLongestPath(int curr, int prev) {
        vector<int> longestPath;
        for (auto next: graph[curr]) {
            if (next != prev) {
                vector<int> candidate = findLongestPath(next, curr);
                if (candidate.size() > longestPath.size()) {
                    longestPath = move(candidate);
                }
            }
        }
        longestPath.push_back(curr);
        return longestPath;
    }
};

class BrutalForce {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        graph = vector<unordered_set<int>>(n);
        for (auto e: edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }

        minHeight = n;
        int heights[n];
        for (int i = 0; i < n; i++) {
            heights[i] = getHeight(i, -1);
            minHeight = min(minHeight, heights[i]);
        }

        vector<int> res = {};
        for (int i = 0; i < n; i++) {
            if (heights[i] == minHeight) {
                res.push_back(i);
            }
        }
        return res;
    }
private:
    vector<unordered_set<int>> graph;
    int minHeight;
    int getHeight(int curr, int prev) {
        int h = 0;
        for (auto next: graph[curr]) {
            if (h > minHeight) {
                return h;
            }
            if (next != prev) {
                h = max(h, 1 + getHeight(next, curr));
            }
        }
        return h;
    }
};

int main() {
    Solution sol;
    int n;
    vector<vector<int>> edges;

    n = 4;
    edges = {{1, 0}, {1,2}, {1,3}};
    cout << "Ans: ";
    for (auto v: sol.findMinHeightTrees(n, edges)) {
        cout << v << " ";
    }
    cout << endl;

    n = 6;
    edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    cout << "Ans: ";
    for (auto v: sol.findMinHeightTrees(n, edges)) {
        cout << v << " ";
    }
    cout << endl;

    n = 1;
    edges = {};
    cout << "Ans: ";
    for (auto v: sol.findMinHeightTrees(n, edges)) {
        cout << v << " ";
    }
    cout << endl;

    n = 2;
    edges = {{0, 1}};
    cout << "Ans: ";
    for (auto v: sol.findMinHeightTrees(n, edges)) {
        cout << v << " ";
    }
    cout << endl;


    return 0;
}
