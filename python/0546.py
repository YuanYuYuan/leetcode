from typing import List


class Solution:

    def removeBoxes(self, boxes: List[int]) -> int:
        dp = dict()
        def dfs(i, j, k):
            if i > j: return 0
            while i < j and boxes[i] == boxes[i+1]:
                i += 1
                k += 1
            if i == j: return (k+1)**2
            if (i, j, k) in dp: return dp[(i, j, k)]
            vmax = (k+1)**2 + dfs(i+1, j, 0)
            for m in range(i+1, j+1):
                if boxes[m] == boxes[i]:
                    vmax = max(vmax, dfs(i+1, m-1, 0) + dfs(m, j, k+1))
            dp[(i, j, k)] = vmax
            return vmax
        return dfs(0, len(boxes)-1, 0)


print(Solution().removeBoxes([1, 3, 2, 2, 2, 3, 4, 3, 1]))
