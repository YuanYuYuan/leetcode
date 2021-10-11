'''
For each position, we use DFS to determine the most
steps to reach the farthest endpoint of some valid path.
'''


from typing import List


class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        steps = [[0] * n for _ in range(m)]
        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

        def traverse(i, j) -> int:
            if steps[i][j] != 0:
                return steps[i][j]

            traversal = 0
            for (di, dj) in directions:
                next_i, next_j = i+di, j+dj
                if 0 <= next_i < m and \
                    0 <= next_j < n and \
                    matrix[next_i][next_j] > matrix[i][j]:
                    traversal = max(traversal, traverse(next_i, next_j))
            steps[i][j] = traversal + 1

            return steps[i][j]

        return max(traverse(i, j)
            for i in range(m)
            for j in range(n)
        )


assert Solution().longestIncreasingPath([[9,9,4],[6,6,8],[2,1,1]]) == False
