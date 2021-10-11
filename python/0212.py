from collections import defaultdict
from typing import List

class TrieNode:
    def __init__(self):
        self.next = defaultdict(TrieNode)
        self.word = ''

class Trie:
    def __init__(self, words):
        self.root = TrieNode()
        for w in words:
            node = self.root
            for c in w:
                node = node.next[c]
            node.word = w


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        out = []
        trie = Trie(words)
        m, n = len(board), len(board[0])

        def dfs(node, i, j):
            if not (0 <= i < m and 0 <= j < n and board[i][j] in node.next): return

            node = node.next[board[i][j]]
            if node.word:
                out.append(node.word)
                # remember to clean
                node.word = ""

            tmp, board[i][j] = board[i][j], '#'
            dfs(node, i+1, j)
            dfs(node, i-1, j)
            dfs(node, i, j+1)
            dfs(node, i, j-1)
            board[i][j] = tmp

        for i in range(m):
            for j in range(n):
                dfs(trie.root, i, j)

        return out




board = [
    ["o","a","a","n"],
    ["e","t","a","e"],
    ["i","h","k","r"],
    ["i","f","l","v"]
]
words = ["oath","pea","eat","rain"]
print(Solution().findWords(board, words))
