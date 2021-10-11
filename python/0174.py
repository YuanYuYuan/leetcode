from typing import List

# The key is using top-down (going backward from the end) and
# set the dp as the minimum hp cost to start from this position.
# Note that the cost means each value is non-positive (<= 0).

class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])

        dungeon[-1][-1] = min(dungeon[-1][-1], 0)

        for i in range(m-2, -1, -1):
            dungeon[i][-1] += dungeon[i+1][-1]
            dungeon[i][-1] = min(dungeon[i][-1] , 0)

        for j in range(n-2, -1, -1):
            dungeon[-1][j] += dungeon[-1][j+1]
            dungeon[-1][j] = min(dungeon[-1][j], 0)

        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                dungeon[i][j] += max(dungeon[i+1][j], dungeon[i][j+1])
                dungeon[i][j] = min(dungeon[i][j], 0)

        return -1 * dungeon[0][0] + 1

#  # with padding
#  class Solution:
#      def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
#          m, n = len(dungeon), len(dungeon[0])
#          MIN = -float('inf')
#          cost = [[MIN] * (n+1) for _ in range(m+1)]
#          cost[-1][-2] = cost[-2][-1] = 0
#          for i in range(m-1, -1, -1):
#              for j in range(n-1, -1, -1):
#                  cost[i][j] = dungeon[i][j] + max(cost[i+1][j], cost[i][j+1])
#                  cost[i][j] = min(cost[i][j], 0)
#          return -1 * cost[0][0] + 1

print(Solution().calculateMinimumHP([
    [-2,-3,3],
    [-5,-10,1],
    [10,30,-5]
]), 7)
print(Solution().calculateMinimumHP([[-10]]), 11)


