'''
# https://leetcode.com/problems/longest-common-subsequence/

Use dp[i][j] to represent the longestCommonSubsequence(text1[:i], text2[:j])
The formula is

    if text1[i] == text2[j]:
        dp[i][j] = dp[i-1][j-1] + 1
    else:
        dp[i][j] = max(dp[i-1][j], dp[i][j-1])

'''

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        dp = [[0] * n for _ in range(m)]

        # initialize the boundary
        dp[0][0] = 1 if text1[0] == text2[0] else 0
        for i in range(1, m):
            dp[i][0] = max(dp[i-1][0], 1 if text1[i] == text2[0] else 0)
        for j in range(1, n):
            dp[0][j] = max(dp[0][j-1], 1 if text1[0] == text2[j] else 0)

        for i in range(1, m):
            for j in range(1, n):
                if text1[i] == text2[j]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[-1][-1]


#  assert Solution().longestCommonSubsequence('abcde', 'ace') == 3
#  assert Solution().longestCommonSubsequence('abc', 'abc') == 3
#  assert Solution().longestCommonSubsequence('abc', 'def') == 0
