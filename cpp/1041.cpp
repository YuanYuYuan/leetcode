#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int head = 0;
        int x = 0;
        int y = 0;
        const int move[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        for (const auto& c: instructions) {
            switch (c) {
                case 'G':
                    x += move[head][0];
                    y += move[head][1];
                    break;
                case 'R':
                    head = (head + 1) % 4;
                    break;
                case 'L':
                    head = (head - 1 + 4) % 4;
                    break;
            }
        }
        return (head != 0 || (x == 0 && y == 0));
    }
};

int main() {
    Solution sol;
    cout << sol.isRobotBounded("GGLLGG") << endl;
    cout << sol.isRobotBounded("GG") << endl;
    cout << sol.isRobotBounded("GL") << endl;
    cout << sol.isRobotBounded("GLRLLGLL") << endl;
    return 0;
}
