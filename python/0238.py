class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        N = len(nums)
        prods = []
        p = 1
        for i in range(N):
            prods.append(p)
            p *= nums[i]

        p = 1
        for i in range(N - 1):
            p *= nums[N - i - 1]
            prods[N - i - 2] *= p

        return prods


sol = Solution()
assert sol.productExceptSelf([1, 2, 3, 4]) == [24, 12, 8, 6]
assert sol.productExceptSelf([-1, 1, 0, -3, 3]) == [0, 0, 9, 0, 0]



