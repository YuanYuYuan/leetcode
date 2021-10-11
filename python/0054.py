from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        T, L, D, R = 0, 0, m-1, n-1

        out = []
        i, j = 0, -1
        while True:
            if j + 1 > R: break
            while j + 1 <= R:
                j += 1
                out.append(matrix[i][j])
            T += 1

            if i + 1 > D: break
            while i + 1 <= D:
                i += 1
                out.append(matrix[i][j])
            R -= 1

            if j - 1 < L: break
            while j - 1 >= L:
                j -= 1
                out.append(matrix[i][j])
            D -= 1

            if i - 1 < T: break
            while i - 1 >= T:
                i -= 1
                out.append(matrix[i][j])
            L += 1
        return out


#  print(Solution().spiralOrder([[1,2,3],[4,5,6],[7,8,9]]))
print(Solution().spiralOrder([[1,2,3,4],[5,6,7,8],[9,10,11,12]]))

