ROMAN = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
}


class Solution:
    def romanToInt(self, s: str) -> int:
        sum = 0
        for idx in range(len(s)-1):
            if ROMAN[s[idx]] < ROMAN[s[idx+1]]:
                sum -= ROMAN[s[idx]]
            else:
                sum += ROMAN[s[idx]]
        return sum + ROMAN[s[-1]]

sol = Solution()
assert sol.romanToInt('III') == 3
assert sol.romanToInt('IV') == 4
assert sol.romanToInt('IX') == 9
assert sol.romanToInt('LVIII') == 58
assert sol.romanToInt('LVIII') == 58
assert sol.romanToInt('MCMXCIV') == 1994
