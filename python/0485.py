from typing import List

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        i = 0
        vmax = 0
        for j, v in enumerate(nums):
            if v == 0:
                vmax = max(vmax, j-i)
                i = j+1
        return max(vmax, len(nums)-i)

print(Solution().findMaxConsecutiveOnes([1, 1, 0, 1, 1, 1]))
print(Solution().findMaxConsecutiveOnes([1, 1, 0, 1, 1, 1, 0]))
print(Solution().findMaxConsecutiveOnes([]))
print(Solution().findMaxConsecutiveOnes([0, 0]))
print(Solution().findMaxConsecutiveOnes([1, 0, 1, 1, 0, 1]))


