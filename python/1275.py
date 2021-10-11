from typing import List


class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        table = [[0] * 8 for _ in range(2)]
        player = 0
        for i, j in moves:
            table[player][i] += 1
            table[player][j+3] += 1
            if i == j:
                table[player][6] += 1
            if i + j == 2:
                table[player][7] += 1
            player = (player + 1) % 2

        for i in range(8):
            if table[0][i] == 3:
                return "A"
            elif table[1][i] == 3:
                return "B"

        return "Draw" if len(moves) == 9 else "Pending"


print(Solution().tictactoe([[0,0],[2,0],[1,1],[2,1],[2,2]]), "A")
print(Solution().tictactoe([[2,0],[1,1],[0,2],[2,1],[1,2],[1,0],[0,0],[0,1]]), "B")

