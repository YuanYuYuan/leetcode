# https://leetcode.com/problems/missing-number/

from typing import List

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        xor = len(nums)
        for (i, n) in enumerate(nums):
            xor ^= i ^ n
        return xor
