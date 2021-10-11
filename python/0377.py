'''
Note that BFS & DFS is not applicable in this problem
since the searching space is too large.

Alternatively, let's use DP.
Let dp[i] stand combinationSum4(nums, i) with
the starting point dp[0] = 1.
'''

from typing import List


class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [1] + [0] * target
        nums = sorted(nums)
        for i in range(1, target+1):
            for n in nums:
                if i < n: break
                else: dp[i] += dp[i - n]
        return dp[-1]


print(Solution().combinationSum4([4, 2, 1], 32))

