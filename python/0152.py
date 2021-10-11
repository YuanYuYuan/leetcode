#  https://leetcode.com/problems/maximum-product-subarray/

class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        curr_max = curr_min = max_prod = nums[0]

        for n in nums[1:]:
            if n < 0:
                curr_min, curr_max = curr_max, curr_min
            curr_max = max(n, curr_max * n)
            curr_min = min(n, curr_min * n)
            max_prod = max(max_prod, curr_max)

        return max_prod




sol = Solution()
assert sol.maxProduct([2, 3, -2, 4]) == 6
assert sol.maxProduct([-2, 0, -1]) == 0
