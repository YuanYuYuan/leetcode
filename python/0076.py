
class Solution:
    def minWindow(self, s, t):
        missing = len(t)
        need = dict()
        for c in t:
            need[c] = need.get(c, 0) + 1

        i = I = J = 0
        for j, c in enumerate(s, 1):
            if c not in need:
                continue
            if need[c] > 0:
                missing -= 1
            need[c] -= 1

            if missing > 0:
                continue

            while i < j:
                if s[i] in need:
                    if need[s[i]] >= 0:
                        break
                    else:
                        need[s[i]] += 1
                i += 1

            if not J or j - i < J - I:
                I, J = i, j

        return s[I:J]



print(Solution().minWindow("ADOBECODEBANC", "ABC"))
print(Solution().minWindow("a", "a"))
print(Solution().minWindow("a", "aa"))


