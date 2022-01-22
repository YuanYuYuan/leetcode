#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        return 0 <= start
            && start < arr.size()
            && arr[start] >= 0
            && (
                arr[start] == 0
                || !(arr[start] *= -1)
                || canReach(arr, start + arr[start])
                || canReach(arr, start - arr[start])
            );
    }
};

int main() {
    Solution sol;
    vector<int> vec;
    int start = 5;

    vec = {4, 2, 3, 0, 3, 1, 2};
    start = 5;
    assert(sol.canReach(vec, start) == true);

    vec = {4, 2, 3, 0, 3, 1, 2};
    start = 0;
    assert(sol.canReach(vec, start) == true);

    vec = {3, 0, 2, 1, 2};
    start = 2;
    assert(sol.canReach(vec, start) == false);

    return 0;
}
