'''
Note that the following algorithm is too slow for this problem,
with complexity O(n^2)


Use dp[i] to represent the position i is reachable.

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        dp = [True] + [False] * (len(nums) - 1)
        for i in range(1, len(nums)):
            dp[i] = any(dp[j] and nums[j] + j >= i for j in range(i))
        return dp[-1]

The problem is nums consists of maximum jumpable step,
so we don't need to compare all indices during each jump.

The key idea is to compare the growing speed of maximum jumpable position m
with nums[:i] and the iteration speed of index i.

The complexity is only O(n).
The following one is the forward version.

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        m = 0
        for (i, n) in enumerate(nums):
            if i > m:
                return False
            m = max(m, i + n)
        return True

However, the backward version seems faster, so the we use it as
our final version.
'''



from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        m = len(nums) - 1
        for i in range(len(nums))[::-1]:
            if i + nums[i] >= m:
                m = i
        return m == 0

print(Solution().canJump([2, 3, 1, 1, 4]))
print(Solution().canJump([2, 0]))
