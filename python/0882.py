from typing import List
import heapq as hq


class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        # distance between two nodes after possible movements
        dist = [[-1] * n for _ in range(n)]
        for (i, j, c) in edges:
            dist[i][j] = dist[j][i] = c

        # maintain a max-heap of each node with max remaining_moves
        heap = []
        hq.heappush(heap, (-maxMoves, 0))
        visited = [False] * n
        total = 0
        while heap:
            remaining_moves, i = hq.heappop(heap)
            remaining_moves *= -1
            if visited[i]:
                continue

            # visit current node
            visited[i] = True
            total += 1

            # move from node i to node j
            for j in range(n):
                if i == j or dist[i][j] == -1:
                    continue
                # it's possible to reach the node j
                if not visited[j] and remaining_moves > dist[i][j]:
                    hq.heappush(heap, (-(remaining_moves - dist[i][j] - 1), j))
                movement = min(remaining_moves, dist[i][j])
                dist[i][j] -= movement
                dist[j][i] -= movement
                total += movement

        return total


edges = [[0,1,10],[0,2,1],[1,2,2]]
maxMoves = 6
n = 3
print(Solution().reachableNodes(edges, maxMoves, n))

edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]]
maxMoves = 10
n = 4
print(Solution().reachableNodes(edges, maxMoves, n))

edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]]
maxMoves = 17
n = 5
print(Solution().reachableNodes(edges, maxMoves, n))

edges = [[0,3,8],[0,1,4],[2,4,3],[1,2,0],[1,3,9],[0,4,7],[3,4,9],[1,4,4],[0,2,7],[2,3,1]]
maxMoves = 8
n = 5
print(Solution().reachableNodes(edges, maxMoves, n))
