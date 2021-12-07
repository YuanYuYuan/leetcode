from itertools import accumulate
from typing import List

class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        return  max(1 - min(accumulate(nums)), 1)
