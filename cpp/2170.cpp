#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> even, odd;
        for (int i = 0; i < nums.size(); i += 2) even[nums[i]] += 1;
        for (int i = 1; i < nums.size(); i += 2) odd[nums[i]] += 1;
        auto findMaxTwo = [](unordered_map<int, int> counter) {
            int fstVal{}, fstCnt{}, sndCnt{};
            for (auto [val, cnt]: counter) {
                if (cnt <= fstCnt) {
                    if (cnt > sndCnt) {
                        sndCnt = cnt;
                    }
                } else {
                    sndCnt = fstCnt;
                    fstVal = val;
                    fstCnt = cnt;
                }
            }
            return make_tuple(fstVal, fstCnt, sndCnt);
        };
        auto [evenFstVal, evenFstCnt, evenSndCnt] = findMaxTwo(even);
        auto [oddFstVal, oddFstCnt, oddSndCnt] = findMaxTwo(odd);
        if (evenFstVal != oddFstVal) return nums.size() - evenFstCnt - oddFstCnt;
        return nums.size() - max(
            evenFstCnt + oddSndCnt,
            evenSndCnt + oddFstCnt
        );
    }
};

int main() {
    // vector<int> vec = {3, 1, 3, 2, 4, 3};
    vector<int> vec = {1, 2, 2, 2, 2};
    cout << Solution().minimumOperations(vec) << endl;
    return 0;
}
