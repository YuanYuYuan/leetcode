# https://leetcode.com/problems/container-with-most-water/

from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        h = min(height[l], height[r])
        out = h * (r - l)
        while l < r:
            if height[l] < height[r]:
                while height[l] <= h:
                    l += 1
                    if l >= r:
                        return out
            else:
                while height[r] <= h:
                    r -= 1
                    if l >= r:
                        return out
            h = min(height[l], height[r])
            out = max(out, h * (r - l))
        return out


sol = Solution()

assert sol.maxArea([1,8,6,2,5,4,8,3,7]) == 49
assert sol.maxArea([1,1]) == 1
assert sol.maxArea([4,3,2,1,4]) == 16
assert sol.maxArea([1,2,1]) == 2
