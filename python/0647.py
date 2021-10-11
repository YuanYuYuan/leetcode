class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0
        for i in range(len(s)):
            for j in range(i, i+2):
                I, J = i, j
                while 0 <= I and J < len(s) and s[I] == s[J]:
                    count += 1
                    I -= 1
                    J += 1
        return count
