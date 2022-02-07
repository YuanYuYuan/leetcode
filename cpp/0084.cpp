#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> indexes;
        heights.push_back(0);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!indexes.empty() && heights[indexes.top()] > heights[i]) {
                int j = indexes.top();
                indexes.pop();
                int start = indexes.empty() ? -1 : indexes.top();
                maxArea = max(maxArea, (i - start - 1) * heights[j]);
            }
            indexes.push(i);
        }
        return maxArea;
    }
};

int main() {
    vector<int> vec = {2, 1, 5, 6, 2, 3};
    Solution sol;
    cout << sol.largestRectangleArea(vec) << endl;
    return 0;
}
