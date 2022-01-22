#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions, int start = 0) {
        if (start >= questions.size()) return 0;
        if (start == questions.size() - 1) return questions[start][0];
        if (mem[start] != 0) return mem[start];
        return mem[start] = max(
            questions[start][0] + mostPoints(questions, start + questions[start][1] + 1),
            mostPoints(questions, start + 1)
        );

    }
private:
    long long mem[long(1e5)]{};
};

int main() {
    // vector<vector<int>> vec = {{3,2},{4,3},{4,4},{2,5}};
    vector<vector<int>> vec = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    cout << Solution().mostPoints(vec) << endl;
    return 0;
}
