class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        N1, N2 = len(num1), len(num2)
        if N2 > N1: return self.addStrings(num2, num1)
        carry = 0

        out = list(num1)
        for i in range(N2):
            sum = int(num1[~i]) + int(num2[~i]) + carry
            carry = sum // 10
            out[~i] = str(sum % 10)

        for i in reversed(range(N1-N2)):
            if carry == 0: break
            sum = int(num1[i]) + carry
            carry = sum // 10
            out[i] = str(sum % 10)

        return ''.join(out) if carry == 0 else ''.join([str(carry)] + out)

print(Solution().addStrings('456', '77'))
print(Solution().addStrings('11', '123'))
print(Solution().addStrings('0', '0'))



