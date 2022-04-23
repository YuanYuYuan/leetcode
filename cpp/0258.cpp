#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) num = num / 10 + num % 10;
        return num;
    }
};

int main() {
    cout << Solution().addDigits(38) << endl;
    return 0;
}
