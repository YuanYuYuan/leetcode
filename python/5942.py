from typing import List

class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        N = len(digits)
        res = set()
        for i in range(N):
            if digits[i] == 0:
                continue
            for j in range(N):
                if j == i:
                    continue
                for k in range(N):
                    if k == i or k == j or digits[k] % 2 != 0:
                        continue
                    res.add(digits[i] * 100 + digits[j] * 10 + digits[k])
        return sorted(list(res))

print(Solution().findEvenNumbers([2, 1, 3, 0]))
