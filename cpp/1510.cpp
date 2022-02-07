#include <iostream>

using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        if (visited[n]) return winnable[n];
        for (int i = 1, j; (j = (n - i*i)) >= 0; i++)
            if (!winnerSquareGame(j))
                return winnable[n] = visited[n] = true;
        visited[n] = true;
        return false;
    }
private:
    bool visited[int(1e5 + 1)] = {true, true};
    bool winnable[int(1e5 + 1)] = {false, true};
};

int main() {
    Solution sol;
    for (int i = 0; i < 10; i++) {
        cout << i << ": " << sol.winnerSquareGame(i) << endl;
    }
    return 0;
}
