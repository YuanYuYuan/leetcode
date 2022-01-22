#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long vmass = mass;
        sort(asteroids.begin(), asteroids.end());
        for (auto a: asteroids) {
            if (vmass >= a) {
                vmass += a;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    // int mass = 10;
    // vector<int> asteroids = {3, 9, 19, 5, 21};
    int mass = 5;
    vector<int> asteroids = {4, 9, 23, 4};
    cout << sol.asteroidsDestroyed(mass, asteroids) << endl;
    return 0;
}
