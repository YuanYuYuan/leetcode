#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        const int N = num1.size();
        const int M = num2.size();
        vector<int> vec(M + N, 0);
        for (int i = N-1; i >= 0; i--) {
            for (int j = M-1; j >= 0; j--) {
                vec[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
                vec[i+j] += vec[i+j+1] / 10;
                vec[i+j+1] %= 10;
            }
        }

        string res{};
        int i{};
        while (vec[i] == 0) i++;
        while (i < vec.size()) {
            res += vec[i] + '0';
            i++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.multiply("0", "0") << endl;
    cout << sol.multiply("2", "3") << endl;
    cout << sol.multiply("123", "456") << endl;
    return 0;
}
