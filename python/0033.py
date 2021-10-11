#  https://leetcode.com/problems/search-in-rotated-sorted-array/


class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l = 0
        r = len(nums)
        side = target >= nums[0]

        while l < r:
            m = (l + r) // 2
            if nums[m] == target:
                return m

            at_right = nums[m] < target
            if (nums[m] >= nums[0]) != side:
                at_right = not at_right

            if at_right:
                l = m + 1
            else:
                r = m
        return -1


sol = Solution()
assert sol.search([4,5,6,7,0,1,2], 0) == 4
assert sol.search([4,5,6,7,0,1,2], 3) == -1
assert sol.search([1], 0) == -1

