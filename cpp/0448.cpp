class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (auto v: nums) {
            int idx = (v >= 0 ? v : -v) - 1;
            if (nums[idx] > 0)  nums[idx] *= -1;
        }
        vector<int> res;
        for (int i{}; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};


