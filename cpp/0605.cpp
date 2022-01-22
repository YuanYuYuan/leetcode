#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;

        int zeros = 1;
        int planted = 0;

        for (const auto& v: flowerbed) {
            if (v == 0) {
                zeros += 1;
            } else {
                planted += (zeros-1) / 2;
                zeros = 0;
                if (planted == n) {
                    return true;
                }
            }
        }
        planted += zeros / 2;
        return planted >= n;
    }
};



int main() {
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    cout << Solution().canPlaceFlowers(flowerbed, 1) << endl;
}
