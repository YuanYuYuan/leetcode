class Solution:
    def tribonacci(self, n: int) -> int:
        a = [0, 1, 1] + [0] * (n-2)
        for i in range(3, n+1):
            a[i] = a[i-1] + a[i-2] + a[i-3]
        return a[n]


