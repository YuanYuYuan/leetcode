from typing import List


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def blk_idx(i, j):
            return 3 * (i // 3) + (j // 3)
        row = [set(map(str, range(1, 10))) for _ in range(9)]
        col = [set(map(str, range(1, 10))) for _ in range(9)]
        blk = [set(map(str, range(1, 10))) for _ in range(9)]

        lst = []
        for i in range(9):
            for j in range(9):
                k = blk_idx(i, j)
                if board[i][j] != '.':
                    k = blk_idx(i, j)
                    row[i].discard(board[i][j])
                    col[j].discard(board[i][j])
                    blk[k].discard(board[i][j])
                else:
                    lst.append((i, j))

        if not lst: return
        check_list = [(i, j, row[i].intersection(col[j], blk[blk_idx(i, j)])) for (i, j) in lst]
        check_list = sorted(check_list, key=lambda x: len(x[2]))

        def try_place(step):
            if step >= len(check_list): return True
            i, j, cand = check_list[step]
            k = blk_idx(i, j)
            for v in cand:
                if v not in row[i] or v not in col[j] or v not in blk[k]:
                    continue
                board[i][j] = v
                row[i].remove(v)
                col[j].remove(v)
                blk[k].remove(v)
                #  print('[%d]: place %s at (%d, %d)' % (step, v, i, j))
                if try_place(step+1): return True
                board[i][j] = '.'
                row[i].add(v)
                col[j].add(v)
                blk[k].add(v)
            return False

        assert try_place(0)


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

Solution().solveSudoku(board)
