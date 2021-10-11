# https://leetcode.com/problems/reverse-bits/

class Solution:
    def reverseBits(self, n: int) -> int:
        rev = 0
        for _ in range(32):
            rev = (rev << 1) + (n & 1)
            n >>= 1

        return rev

orig = 0b00000010100101000001111010011100
print('{:032b}'.format(orig))
rev = Solution().reverseBits(orig)
print('{:032b}'.format(rev))
