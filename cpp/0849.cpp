#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//              [1, 0, 0, 0, 1, 0, 1]
// dist    :  0  0  1  2  3  0  1  0
// max_dist:  0  0  0  0  0  3  3  3
// max_pos :  0  0  0  0  0  2  2  2

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int N = seats.size();

        int i = 0, j = N-1;
        while (seats[i] != 1 && i < N) i += 1;
        while (seats[j] != 1 && j > i) j -= 1;

        int max_dist = max(i, N - j -1);
        int prev = i;
        i += 1;
        while (i <= j) {
            if (seats[i] == 1)  {
                max_dist = max(max_dist, (i - prev) / 2);
                prev = i;
            }
            i += 1;
        }

        return max_dist;
    }
};

int main() {
    vector<int> vec = {0, 0, 1, 0, 0, 0, 0};
    // vector<int> vec = {1, 0, 0, 0, 1, 0, 1};
    // vector<int> vec = {1, 0, 0, 0, 0, 0, 0};
    // vector<int> vec = {0, 0, 0, 0, 0, 0, 1};
    // vector<int> vec = {0, 1};
    // vector<int> vec = {1, 0};
    // vector<int> vec = {0, 1, 0};
    // vector<int> vec = {1, 0, 1};
    cout << Solution().maxDistToClosest(vec) << endl;
    return 0;
}
