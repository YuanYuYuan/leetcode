#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd{};
        vector<long> oddBase{};
        vector<int> even{};
        vector<long> evenBase{};

        long base = 1;
        while (num) {
            int v = num % 10;
            if (v % 2 == 0) {
                even.push_back(v);
                evenBase.push_back(base);
            } else {
                odd.push_back(v);
                oddBase.push_back(base);
            }
            num /= 10;
            base *= 10;
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        int res = 0;
        for (int i = 0; i < even.size(); i++) {
            res += even[i] * evenBase[i];
        }
        for (int i = 0; i < odd.size(); i++) {
            res += odd[i] * oddBase[i];
        }
        return res;
    }
};

int main() {
    cout << Solution().largestInteger(247) << endl;
    return 0;
}
