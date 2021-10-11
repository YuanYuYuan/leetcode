import math

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        if c == 0 or c == 1:
            return True
        i = 0
        j = int(math.sqrt(c))
        while i <= j:
            v = i**2 + j**2
            if v == c:
                return True
            elif v < c:
                i += 1
            else:
                j -= 1
        return False

print(Solution().judgeSquareSum(5), True)
print(Solution().judgeSquareSum(4), True)
print(Solution().judgeSquareSum(3), False)
print(Solution().judgeSquareSum(2), True)
print(Solution().judgeSquareSum(1), True)
print(Solution().judgeSquareSum(0), True)
