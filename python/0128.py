'''
The key point is insert elements in nums into a set (cost O(n)),
and then walk through all the possible consecutive sequence to
find the longest length (also cost O(n)).
'''

from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        max_len = 0
        while num_set:
            l = r = num_set.pop()
            while l-1 in num_set:
                num_set.remove(l-1)
                l -= 1
            while r+1 in num_set:
                num_set.remove(r+1)
                r += 1
            max_len = max(max_len, r - l + 1)
        return max_len
