class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        for(int z = x ^ y; z; z &= z-1)
            count++;
        return count;
    }
};
