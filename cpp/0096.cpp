#include <iostream>

class Solution {
public:
    Solution() {
        a[0] = 1;
        a[1] = 1;
    }
    int numTrees(int n) {
        if (n == 0 || a[n] != 0) return a[n];
        for (int i{}; i < n; i++) {
            a[n] += numTrees(i) * numTrees(n - i - 1);
        }
        return a[n];
    }
private:
    int a[20]{};
};

int main() {
    Solution sol;
    for (int i{}; i < 5; i++) {
        std::cout << sol.numTrees(i) << std::endl;
    }
    return 0;
}
