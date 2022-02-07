#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        if (arr[1] <= arr[0]) return false;
        int prev = arr[0];
        bool upward = true;
        for (int i = 1; i < arr.size(); i++) {
            if (prev == arr[i]) return false;
            if (upward) {
                if (prev > arr[i]) {
                    upward = false;
                }
            } else {
                if (prev < arr[i]) {
                    return false;
                }
            }
            prev = arr[i];
        }
        return !upward;
    }
};

int main() {
    // vector<int> vec = {0, 3, 2, 1};
    vector<int> vec = {2, 1};
    cout << Solution().validMountainArray(vec) << endl;
    return 0;
}
