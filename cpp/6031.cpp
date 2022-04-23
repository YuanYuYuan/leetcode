#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res{};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                int j = i;
                for (int j = k; j >= 0; j--) {
                    int idx = i - j;
                    if (idx < 0 || (res.size() > 0 && idx <= res.back())) {
                        continue;
                    }
                    res.push_back(i - j);
                }
                for (int j = 1; j <= k; j++) {
                    int idx = i + j;
                    if (idx >= nums.size() || (res.size() > 0 && idx <= res.back())) {
                        continue;
                    }
                    res.push_back(i + j);
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> vec = {3, 4, 9, 1, 3, 9, 5};
    int key = 9;
    int k = 1;
    // vector<int> vec = {2, 2, 2, 2, 2};
    // int key = 2;
    // int k = 2;
    for (auto v: Solution().findKDistantIndices(vec, key, k)) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
