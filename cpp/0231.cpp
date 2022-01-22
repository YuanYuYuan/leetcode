#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && !(n & n-1);
    }
};

int main() {
    Solution sol;
    std::cout << sol.isPowerOfTwo(0) << std::endl;
}
