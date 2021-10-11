from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        #  return self.paint_island(grid)
        return self.sink_and_count(grid)

    def paint_island(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

        def traverse(i, j):
            if grid[i][j] == '1':
                grid[i][j] = 'v'
                for (di, dj) in directions:
                    x, y = i + di, j + dj
                    if 0 <= x < m and 0 <= y < n:
                        traverse(x, y)
        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1': count += 1
                traverse(i, j)

        return count

    def sink_and_count(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        def sink(i, j):
            if 0 <= i < m and 0 <= j < n and grid[i][j] == '1':
                grid[i][j] = '0'
                list(map(sink, (i+1, i-1, i, i), (j, j, j+1, j-1)))
                return 1
            return 0
        return sum(sink(i, j) for i in range(m) for j in range(n))


assert Solution().numIslands([
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]) == 1

assert Solution().numIslands([
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]) == 3

