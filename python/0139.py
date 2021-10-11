'''
Let dp[i] stand for wordBreak(s[:i]) == True
For a str s[:j] we can set dp[j] by finding some i < j
such that s[i:j] is in wordDict and dp[i] is also True
'''


from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [True]
        words = set(wordDict)
        max_len = max(map(len, words))
        for j in range(1, len(s) + 1):
            dp.append(any(
                dp[i] and (s[i:j] in words)
                for i in range(max(0, j-max_len), j)
            ))
        return dp[-1]

assert Solution().wordBreak("leetcode", ["leet","code"]) == True
assert Solution().wordBreak("applepenapple", ["apple","pen"]) == True
assert Solution().wordBreak( "catsandog", ["cats","dog","sand","and","cat"]) == False
