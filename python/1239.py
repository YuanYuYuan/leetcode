from typing import List


def mask(str):
    m = 0
    visited = set()
    for c in str:
        if c in visited: return 0
        m += (1 << (ord(c)-ord("a")))
        visited.add(c)
    return m


class Solution:
    def maxLength(self, arr: List[str]) -> int:
        pool = set()
        for m in map(mask, arr):
            if m in pool: continue
            pool |= set(p + m for p in pool if p & m == 0)
            pool.add(m)
        return max(map(lambda p: bin(p).count("1"), pool))


print(Solution().maxLength(["un","iq","ue"]), 4)
print(Solution().maxLength(["cha","r","act","ers"]), 6)
print(Solution().maxLength(["abcdefghijklmnopqrstuvwxyz"]), 26)


