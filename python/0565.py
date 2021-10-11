from typing import List

class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        max_len = 0
        for idx in range(len(nums)):
            if nums[idx] == -1:
                continue
            count = 0
            while nums[idx] >= 0:
                nums[idx], idx = -1, nums[idx]
                count += 1
            max_len = max(max_len, count)
        return max_len

assert Solution().arrayNesting([5, 4, 0, 3, 1, 6, 2]) == 4
assert Solution().arrayNesting([0, 1, 2]) == 1

