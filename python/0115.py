class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        # note the i, j are indices of dp not the ones of s and t
        m, n = len(s)+1, len(t)+1

        # use dp[i][j] to represent the sub-problem of s[:i] and t[:j]
        dp = [[0] * n for _ in range(m)]

        # if t[:j] is empty, then the number of possible substring from s[:i] is [] only.
        for i in range(m):
            dp[i][0] = 1

        for j in range(1, n):
            for i in range(1, m):
                dp[i][j] = dp[i-1][j]
                if s[i-1] == t[j-1]:
                    dp[i][j] += dp[i-1][j-1]

        return dp[-1][-1]


print(Solution().numDistinct("rabbbit", "rabbit"), 3)
print(Solution().numDistinct("babgbag", "bag"), 5)
