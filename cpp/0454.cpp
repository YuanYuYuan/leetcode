#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// 1,2
// -2,-1
// -1,2
// 0,2


class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> count;
        const int N = nums1.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                count[-(nums1[i] + nums2[j])] += 1;
            }
        }

        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res += count[nums3[i] + nums4[j]];
            }
        }
        return res;
    }
};

int main() {
    // vector<vector<int>> vecs = {{1, 2}, {-2, -1}, {-1, 2}, {0, 2}};
    // vector<vector<int>> vecs = {{0}, {0}, {0}, {0}};
    vector<vector<int>> vecs = {{-1,-1}, {-1,1}, {-1,1}, {1,-1}};
    cout << Solution().fourSumCount(vecs[0], vecs[1], vecs[2], vecs[3]) << endl;
    return 0;
}
