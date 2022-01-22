#include <iostream>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        int m = 1;
        while (m < n) m = (m << 1) + 1;
        return m ^ n;
    }
};


int main() {
    Solution sol;
    cout << sol.bitwiseComplement(5) << endl;
    cout << sol.bitwiseComplement(2) << endl;
    cout << sol.bitwiseComplement(0) << endl;
    cout << sol.bitwiseComplement(1) << endl;
    return 0;
}
