#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        vector<bool> visited(k, false);
        for (int n = 1, val = 1; !visited[val]; n++) {
            if (val % k == 0) return n;
            visited[val] = true;
            val = (10 * val + 1) % k;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    cout << sol.smallestRepunitDivByK(1) << endl;
    cout << sol.smallestRepunitDivByK(2) << endl;
    cout << sol.smallestRepunitDivByK(3) << endl;
    cout << sol.smallestRepunitDivByK(5) << endl;
    return 0;
}
