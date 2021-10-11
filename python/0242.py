class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_map = dict()
        t_map = dict()
        for c in s: s_map[c] = s_map.get(c, 0) + 1
        for c in t: t_map[c] = t_map.get(c, 0) + 1
        return s_map == t_map

