from typing import List


class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        res = []
        def dfs(idx, pre, cur, vsum, expr):
            if idx == len(num):
                if vsum == target and cur == 0:
                    res.append(expr)
                return

            cur = cur * 10 + int(num[idx])

            # check possible multiple digits
            if cur > 0:
                dfs(idx+1, pre, cur, vsum, expr)

            # consume cur and append the expression
            # initial
            if not expr:
                dfs(idx+1, cur, 0, cur, str(cur))
            # case by case
            else:
                dfs(idx+1, cur, 0, vsum + cur, expr + '+' + str(cur))
                dfs(idx+1, -cur, 0, vsum - cur, expr + '-' + str(cur))
                dfs(idx+1, pre*cur, 0, vsum - pre + (pre * cur), expr + '*' + str(cur))
        dfs(0, 0, 0, 0, "")
        return res





num = "123"
target = 6
print(Solution().addOperators(num, target), ["1*2*3","1+2+3"])

num = "232"
target = 8
print(Solution().addOperators(num, target), ["2*3+2","2+3*2"])

num = "105"
target = 5
print(Solution().addOperators(num, target), ["1*0+5","10-5"])

num = "00"
target = 0
print(Solution().addOperators(num, target), ["0*0","0+0","0-0"])

num = "3456237490"
target = 9191
print(Solution().addOperators(num, target), [])
