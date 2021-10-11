class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        max_sum = nums[0]
        curr_sum = nums[0]
        for n in nums[1:]:
            if curr_sum < 0:
                curr_sum = n
            else:
                curr_sum += n

            max_sum = max(max_sum, curr_sum)
        return max_sum



sol = Solution()
assert sol.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]) == 6
assert sol.maxSubArray([1]) == 1
assert sol.maxSubArray([5,4,-1,7,8]) == 23
