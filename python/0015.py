# https://leetcode.com/problems/3sum/

from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if nums == []: return []
        nums = sorted(nums)
        print(nums)
        if nums[0] > 0: return []

        N = len(nums)
        ans = []
        for i in range(N-2):
            if nums[i] > 0: break
            if i > 0 and nums[i-1] == nums[i]: continue
            j = i + 1
            k = N - 1
            print(nums[i])
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if sum == 0:
                    ans.append([nums[i], nums[j], nums[k]])
                    j += 1
                    while j < k and nums[j] == nums[j-1]:
                        j += 1
                    k -= 1
                    while j < k and nums[k] == nums[k+1]:
                        k -= 1
                elif sum < 0:
                    j += 1
                    while j < k and nums[j] == nums[j-1]:
                        j += 1
                else:
                    k -= 1
                    while j < k and nums[k] == nums[k+1]:
                        k -= 1
        return ans


sol = Solution()
#  print(sol.threeSum([-1,0,1,2,-1,-4]))
print(sol.threeSum([-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0]))
#  print(sol.threeSum([1,0,-1]))
#  print(sol.threeSum([-2,0,0,2,2]))
