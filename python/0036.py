from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            visited = set()
            for j in range(9):
                v = board[i][j]
                if v != ".":
                    if v in visited:
                        return False
                    else:
                        visited.add(v)

        for j in range(9):
            visited = set()
            for i in range(9):
                v = board[i][j]
                if v != ".":
                    if v in visited:
                        return False
                    else:
                        visited.add(v)

        for x in range(3):
            for y in range(3):
                visited = set()
                for i in range(3):
                    for j in range(3):
                        v = board[3*x + i][3*y + j]
                        if v != ".":
                            if v in visited:
                                return False
                            else:
                                visited.add(v)
        return True

board = [
    ["5","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
]
print(Solution().isValidSudoku(board))

board = [
    ["8","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
]
print(Solution().isValidSudoku(board))
