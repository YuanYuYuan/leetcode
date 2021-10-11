# https://leetcode.com/problems/unique-paths/

'''
1. Simply count all possible combinations of (m-1) move down and (n-1) move right.
    The formula is (m-1 + n-1)! / (m-1)!(n-1)!

2. Dynamic Programming

Let dp[i][j] denote the number of unqiue paths to arrive the point (i, j) in the m x n grid.
Since the robot can only move right or down, state equation: dp[i][j] = dp[i][j-1] + dp[i-1][j]

            (i-1, j)
                |
                V
(i, j-1)  ->  (i, j)

with initial condition dp[0, :] = dp[:, 0] = 1

Example:

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[1 for _ in range(n)] for _ in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i][j-1] + dp[i-1][j]
        return dp[-1][-1]

3. Improved version of DP

space complexity: O(n), the idea is we only need to store the state of columns in each row

'''

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [1 for _ in range(n)]
        for _ in range(1, m):
            for j in range(1, n):
                dp[j] += dp[j - 1]
        return dp[-1]


