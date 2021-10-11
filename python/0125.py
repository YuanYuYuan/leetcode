class Solution:

    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s)-1
        while i < j:
            while not s[i].isalnum() and i < j: i += 1
            while not s[j].isalnum() and i < j: j -= 1
            if i == j: return True
            if s[i].upper() == s[j].upper():
                i += 1
                j -= 1
            else:
                return False
        return True


assert Solution().isPalindrome("A man, a plan, a canal: Panama") == True
assert Solution().isPalindrome("race a car") == False

