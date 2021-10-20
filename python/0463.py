from typing import List
from operator import __ne__


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        M, N = len(grid), len(grid[0])
        out = sum(grid[i][j] for i in range(M) for j in range(N)) * 4
        out -= sum(grid[i][j] * grid[i][j+1] for i in range(M) for j in range(N-1)) * 2
        out -= sum(grid[i][j] * grid[i+1][j] for i in range(M-1) for j in range(N)) * 2
        return out


grid = [
    [0,1,0,0],
    [1,1,1,0],
    [0,1,0,0],
    [1,1,0,0]
]
print(Solution().islandPerimeter(grid), 16)

grid = [
    [1],
]
print(Solution().islandPerimeter(grid), 4)


grid = [
    [1, 0],
]
print(Solution().islandPerimeter(grid), 4)

