class Solution:
    def calculate(self, s: str) -> int:
        summ, curr, sign = 0, 0, 1
        stack = []
        for c in s:
            if c.isdigit():
                curr = curr * 10 + int(c)
            elif c in "+-":
                summ += sign * curr
                curr = 0
                sign = 1 if c == "+" else -1
            elif c == "(":
                stack.append((summ, sign))
                summ, sign = 0, 1
            elif c == ")":
                summ += sign * curr
                curr = 0
                pre_summ, pre_sign = stack.pop()
                summ = pre_summ + summ * pre_sign
        return summ + sign * curr




print(Solution().calculate("1 + 1"))
print(Solution().calculate(" 2-1 + 2 "))
print(Solution().calculate("(1+(4+5+2)-3)+(6+8)"))
print(Solution().calculate("- (-1 + 1) + 1"))
