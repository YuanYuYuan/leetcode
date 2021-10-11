'''
Consider using BFS

'''


class Solution:
    def numSquares(self, n: int) -> int:
        elements = []
        for i in range(1, n+1):
            v = i ** 2
            # important
            if v == n:
                return 1
            elif v < n:
                elements.append(v)
            else:
                break

        level = {0}
        for i in range(n+1):
            new_level = set()
            for l in level:
                for e in elements:
                    if (v := l + e) > n:
                        break
                    elif v == n:
                        return i + 1
                    else:
                        new_level.add(v)
            level = new_level
        return -1

assert Solution().numSquares(12) == 3
assert Solution().numSquares(13) == 2


