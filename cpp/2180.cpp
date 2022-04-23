#include <iostream>

using namespace std;

class Solution {
public:
    int countEven(int num) {
        int count = 0;
        for (int i = 2; i <= num; i++) {
            if (isEven(i)) {
                count += 1;
            }
        }
        return count;
    }
private:
    bool isEven(int num) {
        int res = 0;
        while (num) {
            res = (res + (num % 10)) % 2;
            num /= 10;
        }
        return res == 0;
    }
};

int main() {
    cout << Solution().countEven(30) << endl;
    return 0;
}
