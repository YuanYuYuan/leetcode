#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        const int N = arr.size();
        unordered_map<int, vector<int>> dict = {};
        for (int i = 0; i < arr.size(); i++) {
            dict[arr[i]].push_back(i);
        }

        vector<long long> prefix_sum(N, 0);
        for (auto p: dict) {
            vector<int> v = p.second;
            for (int i = 1; i < v.size(); i++) {
                prefix_sum[v[i]] = prefix_sum[v[i-1]] + i * (v[i] - v[i-1]);
            }
        }


        vector<long long> postfix_sum(N, 0);
        for (auto p: dict) {
            vector<int> v = p.second;
            for (int i = v.size() - 2; i >= 0; i--) {
                postfix_sum[v[i]] = postfix_sum[v[i+1]] + (v.size() - 1 - i) * (v[i+1] - v[i]);
            }
        }

        vector<long long> res(N, 0);
        for (int i = 0; i < N; i++) {
            res[i] = prefix_sum[i] + postfix_sum[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    arr = {2, 1, 3, 1, 2, 3, 3};
    for (auto v: sol.getDistances(arr)) {
        cout << v << " ";
    }
    return 0;
}

// 1 3 4 9
// 13 9 9 19

// 1: 2 + 3 + 8 = 13 = 17 - 4 * 1
// 3: 2 + 1 + 6 = 9 =

// 1 4 8 17
