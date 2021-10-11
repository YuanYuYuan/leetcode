from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        vmax = prev = 0
        for n in nums:
            vmax, prev = max(vmax, prev + n), vmax
        return vmax

print(Solution().rob([1, 2, 3, 1]))


'''
      X, 1, 2, 3, 1
vmax: 0, 1, 2, 4, 4
prev: 0, 0, 1, 2, 4
'''
