from typing import List


class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        for idx in range(1, len(shifts)):
            shifts[~idx] += shifts[~(idx-1)]
        return ''.join(chr(ord('a') + (ord(c) - ord('a') + s) % 26) for (c, s) in zip(s, shifts))

print(Solution().shiftingLetters("ruu", [26, 9, 17]))
print(Solution().shiftingLetters("abc", [3, 5, 9]))
print(Solution().shiftingLetters("aaa", [1, 2, 3]))
