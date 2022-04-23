#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0;
        int j = height.size() - 1;

        while (i < j) {
            int h = min(height[i], height[j]);
            res = max(res, h * (j-i));
            while (i < j && height[i] <= h) i++;
            while (i < j && height[j] <= h) j--;
        }
        return res;
    }
};

int main() {
    // vector<int> vec = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> vec = {1, 1};
    cout << Solution().maxArea(vec) << endl;
    return 0;
}
