#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int table[] = {
            12,23,34,45,56,67,78,89,
            123,234,345,456,567,678,789,
            1234,2345,3456,4567,5678,6789,
            12345,23456,34567,45678,56789,
            123456,234567,345678,456789,
            1234567,2345678,3456789,
            12345678,23456789,
            123456789
        };
        const int N = size(table);
        vector<int> res;
        for (int i = 0; i < N; i++) {
            if (table[i] >= low && table[i] <= high) {
                res.push_back(table[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    for (auto v: sol.sequentialDigits(1000, 13000)) {
        cout << v << endl;
    }
    return 0;
}
