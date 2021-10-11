from typing import List, Tuple

def two_dim_dp(s1: str, s2: str, s3: str) -> bool:
    if (len(s1) + len(s2)) != len(s3):
        return False

    dp = [
        [True for _ in range(len(s2)+1)]
        for _ in range(len(s1)+1)
    ]
    for i in range(len(s1)):
        dp[i+1][0] = dp[i][0] and s1[i] == s3[i]
    for j in range(len(s2)):
        dp[0][j+1] = dp[0][j] and s2[j] == s3[j]

    for i in range(len(s1)):
        for j in range(len(s2)):
            dp[i+1][j+1] = \
                dp[i][j+1] and s1[i] == s3[i+j+1] or \
                dp[i+1][j] and s2[j] == s3[i+j+1]
    return dp[-1][-1]


def dfs(s1: str, s2: str, s3: str) -> bool:
    if (len(s1) + len(s2)) != len(s3):
        return False

    stack: List[Tuple[int, int]] = [(0, 0)]
    visited = set((0, 0))
    while stack:
        (i, j) = stack.pop()
        if i + j == len(s3):
            return True

        if all((
            i+1 <= len(s1),
            (i+1, j) not in visited,
            s1[i] == s3[i+j],
        )):
            stack.append((i+1, j))
            visited.add((i+1, j))

        if all((
            j+1 <= len(s2),
            (i, j+1) not in visited,
            s2[j] == s3[i+j]
        )):
            stack.append((i, j+1))
            visited.add((i, j+1))

    return False



class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        #  return two_dim_dp(s1, s2, s3)
        return dfs(s1, s2, s3)


sol = Solution()
assert sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") == True
assert sol.isInterleave("aabcc", "dbbca", "aadbbbaccc") == False
assert sol.isInterleave("", "", "") == True
