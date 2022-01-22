#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int res = 1;
        for (int tmp = num; tmp > 0; tmp >>= 1) {
            res <<= 1;
        }
        return res - num - 1;
    }
};

int main() {
    Solution sol;
    cout << sol.findComplement(1);
    return 0;
}
