from typing import List

def rob_I(nums: List[int]) -> int:
    prev, now = 0, 0
    for n in nums:
        prev, now = now, max(now, prev + n)
    return now


class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1: return nums[0]
        return max(
            rob_I(nums[1:]),
            rob_I(nums[:-1])
        )


print(Solution().rob([2, 3, 2]))
