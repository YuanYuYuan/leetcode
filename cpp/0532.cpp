#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        unordered_set<int> left;
        unordered_set<int> visited;
        for (const auto& v: nums) {
            int l = v - k;
            int r = v + k;
            if (visited.count(l) && !left.count(l)) {
                count += 1;
                left.insert(l);
            }
            if (visited.count(r) && !left.count(v))  {
                count += 1;
                left.insert(v);
            }
            visited.insert(v);
        }
        return count;
    }
};

int main() {
    vector<int> vec;
    vec = {3, 1, 4, 1, 5};
    cout << Solution().findPairs(vec, 2) << endl;
    vec = {1, 2, 3, 4, 5};
    cout << Solution().findPairs(vec, 1) << endl;
    vec = {1, 3, 1, 5, 4};
    cout << Solution().findPairs(vec, 0) << endl;
    vec = {6, 3, 5, 7, 2, 3, 3, 8, 2, 4};
    cout << Solution().findPairs(vec, 2) << endl;
    vec = {1, 2, 4, 4, 3, 3, 0, 9, 2, 3};
    cout << Solution().findPairs(vec, 3) << endl;
    return 0;
}
