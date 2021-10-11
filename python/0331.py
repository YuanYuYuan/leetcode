class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        if preorder == '#':
            return True

        if preorder[0] == '#' or preorder[-1] != '#':
            return False

        n = 2
        i = 2
        while i < len(preorder)-1:
            if preorder[i] == '#':
                if n <= 1:
                    return False
                else:
                    n -= 1
            else:
                n += 1
            while preorder[i] != ',':
                i += 1
            i += 1
        return n == 1



assert Solution().isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") == True
assert Solution().isValidSerialization("1,#") == False
assert Solution().isValidSerialization("11,#") == False
assert Solution().isValidSerialization("9,#,#,1") == False
