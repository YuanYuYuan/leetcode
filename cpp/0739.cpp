#include <vector>
#include <stack>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int N = temperatures.size();
        if (N == 1) return {0};
        stack<int> stk;
        stk.push(0);
        vector<int> res(N, 0);

        for (int j = 1; j < N; j++) {
            while (!stk.empty()) {
                int i = stk.top();
                if (temperatures[i] >= temperatures[j]) break;
                res[i] = j - i;
                stk.pop();
            }
            stk.push(j);
        }
        return res;
    }
};

/*
 * in: [73, 74, 75, 71, 69, 72, 76, 73]
 * out: [1, 1, 4, 2, 1, 1, 0, 0]
*/

int main() {
    Solution sol;
    vector<int> vec = {74, 73};
    for (auto v: sol.dailyTemperatures(vec)) {
        cout << v << " ";
    }
    return 0;
}
