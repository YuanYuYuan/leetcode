'''
https://leetcode.com/problems/longest-increasing-subsequence/

This is related to Patience Sorting.

Let dp[i] represents the smallest tail of all possible increasing subsequences of size i+1.

time  | ---------->
nums  | 6 8 2 5 3 9
-------------------
dp[0] | 6 6 2 2 2 2
dp[1] |   8 8 5 3 3
dp[2] |           9

Note that for each time, we only modified the dp by one element.
Like update the stale dp[i] for some i, or append the element
in the end of dp.

And the insertion can be done in binary search since
dp is a increasing array in each time.
'''

from typing import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [nums[0]]
        for x in nums[1:]:
            if x > dp[-1]:
                dp.append(x)
            else:
                # find the position of x to replace dp[i+1] < x <= dp[i]
                i, j = 0, len(dp)
                while i != j:
                    m = (i + j) // 2
                    if x > dp[m]:
                        i = m + 1
                    elif x == dp[m]:
                        i = m
                        break
                    else:
                        j = m
                dp[i] = x
        return len(dp)

assert Solution().lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]) == 4



