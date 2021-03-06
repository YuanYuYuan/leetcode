from typing import List


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for i in range(len(triangle)-2, -1, -1):
            for j in range(len(triangle[i])):
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1])
        return triangle[0][0]


#  0
#  1 2
#  3 4 5
#  6 7 8 9


print(
    Solution().minimumTotal([
        [2],
        [3,4],
        [6,5,7],
        [4,1,8,3]
    ]),
    11
)


print(
    Solution().minimumTotal([
        [-11],
    ]),
    -11
)



