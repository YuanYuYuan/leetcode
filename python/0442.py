from typing import List


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        out = []
        for i in range(len(nums)):
            v = abs(nums[i])
            if nums[v - 1] < 0:
                out.append(v)
            else:
                nums[v - 1] *= -1
        return out

print(Solution().findDuplicates([4,3,2,7,8,2,3,1]))
print(Solution().findDuplicates([1,1,2]))
print(Solution().findDuplicates([1]))



