class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        N = len(palindrome)
        M = N // 2
        if N < 2: return ""
        i = 0

        while i < M and palindrome[i] == "a":
            i += 1

        if i == M:
            return palindrome[:-1] + "b"
        else:
            return palindrome[:i] + "a" + palindrome[i+1:]
