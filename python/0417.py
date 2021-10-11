'''
This problem is similar to 329. Longest Increasing Path in a Matrix.

1. We can start from left and top boundary, and use DFS to traverse
all reachable points.
2. Apply the same way on starting from right and bottom boundary.
3. Find the intersection of the two reachable point sets.
'''


from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights), len(heights[0])
        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

        def traverse(i, j, visited):
            if (i, j) not in visited:
                visited.add((i, j))
                for (di, dj) in directions:
                    next_i, next_j = i + di, j + dj
                    if 0 <= next_i < m and \
                        0 <= next_j < n and \
                        heights[next_i][next_j] >= heights[i][j]:
                        traverse(next_i, next_j, visited)

        visited_lt, visited_rb = set(), set()
        for i in range(m):
            traverse(i, 0, visited_lt)
            traverse(i, n-1, visited_rb)

        for j in range(n):
            traverse(0, j, visited_lt)
            traverse(m-1, j, visited_rb)

        return list(visited_lt & visited_rb)

print(Solution().pacificAtlantic([
    [1,2,2,3,5],
    [3,2,3,4,4],
    [2,4,5,3,1],
    [6,7,1,4,5],
    [5,1,1,2,4]
]))

