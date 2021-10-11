from typing import List


class Solution:
    def is_substring(self, substring, string):
        i = 0
        for c in string:
            if c == substring[i]:
                i += 1
            if i == len(substring):
                return True
        return False

    def findLUSlength(self, strs: List[str]) -> int:
        strs = sorted(strs, key=len, reverse=True)
        checked = set()
        for i in range(len(strs)):
            if strs[i] in checked:
                continue
            no_substr = True
            visited = set()
            for j in range(len(strs)):
                if i == j or strs[j] in visited:
                    continue
                if len(strs[i]) > len(strs[j]):
                    break
                if self.is_substring(strs[i], strs[j]):
                    no_substr = False
                    break
                visited.add(strs[j])
            if no_substr:
                return len(strs[i])
            checked.add(strs[i])
        return -1

print(Solution().findLUSlength(["aba","cdc","eae"]))
print(Solution().findLUSlength(["aaa","aaa","aa"]))
print(Solution().findLUSlength(["aabbcc", "aabbcc","cb"]))
print(Solution().findLUSlength(["a","b","c","d","e","f","a","b","c","d","e","f"]))


