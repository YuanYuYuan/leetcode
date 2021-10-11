from typing import List


class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        even, odd = 0, 1
        while True:
            # find 1st misplaced even
            while even < len(nums) and nums[even] % 2 == 0:
                even += 2

            if even >= len(nums):
                break

            # if misplaced even exists, find the 1st misplaced odd
            while nums[odd] % 2 == 1:
                odd += 2

            # switch them
            nums[even], nums[odd] = nums[odd], nums[even]
        return nums

print(Solution().sortArrayByParityII([4,2,5,7]))
print(Solution().sortArrayByParityII([2,3]))


