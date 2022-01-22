#include <string>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> layers{};
        for (const auto& row: bank) {
            int num = accumulate(
                row.begin(),
                row.end(),
                0,
                [](int vsum, char c) -> int { return vsum + c - '0';}
            );
            if (num > 0) {
                layers.push_back(num);
            }
        }

        int total = 0;
        for (int i = 1; i < layers.size(); i++) {
            total += layers[i] * layers[i-1];
        }
        return total;
    }
};


int main() {
    Solution sol;
    // vector<string> banks = {"011001","000000","010100","001000"};
    vector<string> banks = {"000","111","000"};
    cout << sol.numberOfBeams(banks) << endl;
    return 0;
}
