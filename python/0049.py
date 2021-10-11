from typing import List
from collections import Counter
import itertools
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs):
        out = defaultdict(list)
        for word in strs:
            out[tuple(sorted(word))].append(word)
        return list(out.values())


print(Solution().groupAnagrams(["eat","tea","tan","ate","nat","bat"]))
