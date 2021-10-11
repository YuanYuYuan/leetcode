# https://leetcode.com/problems/counting-bits/


from typing import List

class Solution:
    def countBits(self, n: int) -> List[int]:
        count = [0]
        for v in range(1, n + 1):
            count.append(count[v // 2] + v % 2)
        return count

print(Solution().countBits(5))


