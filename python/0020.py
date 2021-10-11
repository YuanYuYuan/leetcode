pair = {
    ')': '(',
    ']': '[',
    '}': '{',
}

class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2: return False
        stack = []
        for p in s:
            if p in pair:
                if not stack or stack.pop() != pair[p]:
                    return False
            else:
                stack.append(p)

        return not stack

print(Solution().isValid("()"))
print(Solution().isValid("()[]{}"))
print(Solution().isValid("(]"))
print(Solution().isValid("([)]"))
print(Solution().isValid("{[]}"))
print(Solution().isValid("(){}}{"))
print(Solution().isValid("[({(())}[()])]"))
