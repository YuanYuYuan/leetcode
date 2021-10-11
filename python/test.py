from typing import List

class Solution:

    def solveSudoku(self, board: List[List[str]]) -> None:

        def returnMinItem(possible_values):
            return min(possible_values.items(), key=lambda x: len(x[1]))[0]

        def placeNextDigit(board, possible_values):
            i, j = returnMinItem(possible_values)
            numbers = possible_values.pop((i, j))

            for n in numbers:
                board[i][j] = n
                if not possible_values:
                    return

                discarded = []

                for (i2, j2), v in possible_values.items():
                    if (i == i2 or j == j2 or (i // 3, j // 3) == (i2 // 3, j2 // 3)) and n in v:
                        if len(v) == 1:
                            for v in discarded:
                                v.add(n)
                            possible_values[i, j] = numbers
                            return
                        v.discard(n)
                        discarded.append(v)

                placeNextDigit(board, possible_values)

                if not possible_values:
                    return

                for v in discarded:
                    v.add(n)

            possible_values[i, j] = numbers


        possible_values = {(i, j): {"1", "2", "3", "4", "5", "6", "7", "8", "9"} \
                                 - {board[i][k] for k in range(9)} \
                                 - {board[k][j] for k in range(9)} \
                                 - {board[3 * (i // 3) + di][3 * (j // 3) + dj]
                                    for di in range(3) for dj in range(3)}
                            for i in range(9) for j in range(9)
                            if board[i][j] == '.'}

        i, j = returnMinItem(possible_values)
        while possible_values and len(possible_values[i, j]) == 1:
            for n in possible_values.pop((i, j)):
                board[i][j] = n
                for (i2, j2), v in possible_values.items():
                    if (i == i2 or j == j2 or (i // 3, j // 3) == (i2 // 3, j2 // 3)) and n in v:
                        v.discard(n)
            if possible_values:
                i, j = returnMinItem(possible_values)
        if possible_values:
            placeNextDigit(board, possible_values)
