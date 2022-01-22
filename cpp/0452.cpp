#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        // sort(
        //     points.begin(),
        //     points.end(),
        //     [&](vector<int> p1, vector<int> p2) {
        //         return (p1[0] == p2[0]) ? (p1[1] <= p2[1]) : (p1[0] <= p2[0]);
        //     }
        // );
        // for (const auto& pos: points) {
        //     cout << "(" << pos[0] << ", " << pos[1] << ")" << endl;
        // }

        map<int, int> interval_i_to_j;
        for (const auto& pos: points) {
            int i = pos[0];
            if (interval_i_to_j.find(i) == interval_i_to_j.end()) {
                interval_i_to_j[i] = pos[1];
            } else {
                interval_i_to_j[i] = min(interval_i_to_j[i], pos[1]);
            }
        }

        // for (const auto& pair: interval_i_to_j) {
        //     auto [i, j] = pair;
        //     cout << "(" << i << ", " << j << ")" << endl;
        // }

        int J = -1;
        int count = 1;
        for (const auto& pair: interval_i_to_j) {
            const auto& [i, j] = pair;
            if (J == -1) {
                J = j;
            } else {
                if (i > J) {
                    J = j;
                    count += 1;
                } else {
                    J = min(J, j);
                }
            }
        }
        return count;
    }
};

int main() {
    // vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    // vector<vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};
    vector<vector<int>> points = {{1,2},{2,3},{3,4},{4,5}};
    cout << Solution().findMinArrowShots(points) << endl;
    return 0;
}
