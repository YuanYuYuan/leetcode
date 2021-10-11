from typing import List

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        cur = out = 0
        for i in range(0, len(nums)-2):
            if nums[i+2] + nums[i] == 2 * nums[i+1]:
                cur += 1
                out += cur
            else:
                cur = 0
        return out

print(Solution().numberOfArithmeticSlices([1, 2, 3, 4]))
print(Solution().numberOfArithmeticSlices([1]))





