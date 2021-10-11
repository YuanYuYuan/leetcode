class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not len(s): return ""
        max_i = max_j = max_len = 0
        for i in range(len(s)):
            for j in range(i, i+2):
                beg, end = i, j
                while 0 <= beg and end < len(s) and s[beg] == s[end]:
                    beg -= 1
                    end += 1
                cur_len = end - beg - 1
                if max_len < cur_len:
                    max_len = cur_len
                    max_i, max_j = beg, end
        return s[max_i+1:max_j]


print(Solution().longestPalindrome("babad"))
print(Solution().longestPalindrome("cbbd"))
print(Solution().longestPalindrome("a"))
print(Solution().longestPalindrome("ac"))
