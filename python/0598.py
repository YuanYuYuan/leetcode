from typing import List


class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        M, N = m, n
        for op in ops:
            M = min(M, op[0])
            N = min(N, op[1])
        return M * N

print(Solution().maxCount(m = 3, n = 3, ops = [[2,2],[3,3]]))
print(Solution().maxCount(m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]))
print(Solution().maxCount(m = 3, n = 3, ops = []))


