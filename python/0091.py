# https://leetcode.com/problems/decode-ways/

class Solution:
    def numDecodings(self, s: str) -> int:
        N = len(s)
        if N == 0 or s[0] == '0': return 0
        curr, prev = 1, 1
        for i in range(1, N):
            count = 0
            if s[i] != '0':
                count += curr
            if 10 <= int(s[i-1:i+1]) <= 26:
                count += prev
            curr, prev = count, curr
        return curr


assert Solution().numDecodings('0') == 0
assert Solution().numDecodings('06') == 0
assert Solution().numDecodings('226') == 3
