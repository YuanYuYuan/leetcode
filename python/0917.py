class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        i, j = 0, len(s) - 1
        lst = list(s)
        while i < j:
            if not s[i].isalpha():
                i += 1
            elif not s[j].isalpha():
                j -= 1
            else:
                lst[i], lst[j] = lst[j], lst[i]
                i += 1
                j -= 1
        return "".join(lst)


print(Solution().reverseOnlyLetters("ab-cd"), "dc-ba")
print(Solution().reverseOnlyLetters("a-bC-dEf-ghIj"), "j-Ih-gfE-dCba")
print(Solution().reverseOnlyLetters( "Test1ng-Leet=code-Q!"), "Qedo1ct-eeLg=ntse-T!")
