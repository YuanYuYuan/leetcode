'''
DFS
'''


from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])

        def dfs(i, j, k):
            if k >= len(word): return True
            if not (0 <= i < m and 0 <= j < n): return False
            if board[i][j] != word[k]: return False

            tmp = board[i][j]
            board[i][j] = "#"
            for (di, dj) in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                if dfs(i+di, j+dj, k+1): return True
            board[i][j] = tmp
            return False

        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False

#  board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
#  word = "ABCCED"
#  assert Solution().exist(board, word) == True

#  board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
#  word = "SEE"
#  assert Solution().exist(board, word) == True

#  board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
#  word = "ABCB"
#  assert Solution().exist(board, word) == False

#  board = [["a","a"]]
#  word = "aaa"
#  assert Solution().exist(board, word) == False

board = [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
word = "ABCESEEEFS"
assert Solution().exist(board, word) == True

