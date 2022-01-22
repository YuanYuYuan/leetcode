#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        cout << lowerbound(fruits, startPos, k);
        cout << upperbound(fruits, startPos, k);
        return 0;
    }
private:
    int lowerbound(vector<vector<int>>& fruits, int startPos, int k) {
        int lo = 0;
        int hi = fruits.size();
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (fruits[mi][0] < startPos - k) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return lo;
    }

    int upperbound(vector<vector<int>>& fruits, int startPos, int k) {
        int lo = 0;
        int hi = fruits.size();
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (fruits[mi][0] > startPos - k) {
                hi = mi - 1;
            } else {
                lo = mi;
            }
        }
        return hi;
    }
};

int main() {
    vector<vector<int>> fruits = {{2,8},{6,3},{8,6}};
    int startPos = 5 ;
    int k = 4;
    Solution sol;
    cout << sol.maxTotalFruits(fruits, startPos, k) << endl;
    return 0;
}
