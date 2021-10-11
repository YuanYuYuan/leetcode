class Solution:

    def maxTurbulenceSize(self, A):
        best = clen = 0

        for i in range(len(A)):
            if i >= 2 and (A[i-2] > A[i-1] < A[i] or A[i-2] < A[i-1] > A[i]):
                clen += 1
            elif i >= 1 and A[i-1] != A[i]:
                clen = 2
            else:
                clen = 1
            best = max(best, clen)
        return best



print(Solution().maxTurbulenceSize([9, 4, 2, 10, 7, 8, 8, 1, 9]), 5)
print(Solution().maxTurbulenceSize([4, 8, 12, 16]), 2)
print(Solution().maxTurbulenceSize([9, 9]), 1)
print(Solution().maxTurbulenceSize([9, 9, 9]), 1)
print(Solution().maxTurbulenceSize([100]), 1)
print(Solution().maxTurbulenceSize([0, 8, 45, 88, 48, 68, 28, 55, 17, 24]), 8)
