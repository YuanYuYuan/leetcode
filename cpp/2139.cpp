#include <algorithm>
#include <iostream>


using namespace std;

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if (target == 1) return 0;
        if (maxDoubles == 0) return target - 1;
        return 1 + (
            (target % 2 == 0)
            ? minMoves(target / 2, maxDoubles - 1)
            : minMoves(target - 1, maxDoubles)
        );
    }
};

int main() {
    cout << Solution().minMoves(5, 0) << endl;
    cout << Solution().minMoves(19, 2) << endl;
    cout << Solution().minMoves(10, 4) << endl;
    return 0;
}

