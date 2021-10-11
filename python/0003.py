'''
Needed to rewrite.
'''

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        if n <= 1: return n

        prev_pos = {}
        prev_start = -1
        max_len = 1
        for (i, c) in enumerate(s):
            if c in prev_pos:
                max_len = max(max_len, i - prev_start - 1)
                prev_start = max(prev_pos[c], prev_start)
            prev_pos[c] = i
        return max(max_len, n - prev_start - 1)

print(Solution().lengthOfLongestSubstring("abba"), 2)
print(Solution().lengthOfLongestSubstring("cd"), 2)
print(Solution().lengthOfLongestSubstring("cdd"), 2)
print(Solution().lengthOfLongestSubstring("cddf"), 2)
print(Solution().lengthOfLongestSubstring("ccd"), 2)
print(Solution().lengthOfLongestSubstring("abcabcbb"))

