class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hash = dict()
        for (i, n) in enumerate(nums):
            if n in hash:
                return [i, hash[n]]
            else:
                hash[target - n] = i


sol = Solution()

nums = [2,7,11,15]
target = 9
anws = [0,1]

assert set(sol.twoSum(nums, target)) == set(anws)

nums = [3,2,4]
target = 6
anws = [1,2]

assert set(sol.twoSum(nums, target)) == set(anws)

nums = [3,3]
target = 6
anws = [0,1]

assert set(sol.twoSum(nums, target)) == set(anws)
