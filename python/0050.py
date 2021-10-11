class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        elif n == -1:
            return 1 / self.myPow(x, -n)
        elif n % 2 == 0:
            return self.myPow(x*x, n//2)
        else:
            return x * self.myPow(x, n-1)


print(Solution().myPow(2.0, 10))
print(Solution().myPow(2.1, 3))
print(Solution().myPow(2.0, -2))



