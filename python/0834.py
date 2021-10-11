from typing import List
from collections import deque


class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        graph = dict()
        for i, j in edges:
            graph[i] = graph.get(i, []) + [j]
            graph[j] = graph.get(j, []) + [i]

        print(graph)
        return []


print(Solution().sumOfDistancesInTree(6, [[2,5], [0,1],[0,2],[2,3],[4,2]]))
#  print(Solution().sumOfDistancesInTree(1, []))
#  print(Solution().sumOfDistancesInTree(2, [[1,0]]))
#  print(Solution().sumOfDistancesInTree(3, [[2,1],[0,2]]))
#  print(Solution().sumOfDistancesInTree(5, [[2,3],[0,3],[4,1],[4,3]]))
#  print(Solution().sumOfDistancesInTree(4, [[2,0],[1,0],[2,3]]))

