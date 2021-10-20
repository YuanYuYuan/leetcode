#include <iostream>

const int ANS = 6;

int guess(int num) {
    if (num < ANS) {
        return 1;
    } else if (num > ANS) {
        return -1;
    } else {
        return 0;
    }
}

class Solution {
public:
    int guessNumber(int n) {
        int i = 1;
        int j = n;
        while (true) {
            // Do not use direct average, otherwise TLE
            // int myAns = (i+j) / 2;
            int myAns = i + (j-i) / 2;
            int response = guess(myAns);
            if (response > 0) {
                i = myAns + 1;
            } else if (response < 0) {
                j = myAns - 1;
            } else {
                return myAns;
            }
        }
    }
};

int main() {
    Solution sol;
    std::cout << sol.guessNumber(10);
    return 0;
}
