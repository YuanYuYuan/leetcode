from typing import List
from collections import Counter


class Solution:
    def intersect(self, nums1, nums2):
        a, b = map(Counter, (nums1, nums2))
        return list((a & b).elements())

#  nums1 = [1,2,2,1]
#  nums2 = [2,2]
nums1 = [4,9,5]
nums2 = [9,4,9,8,4]
print(Solution().intersect(nums1, nums2))


