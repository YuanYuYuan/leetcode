class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

from collections import deque

class Solution:
    def cloneGraph(self, node: "Node") -> "Node":
        #  return self.clone_graph_bfs(node)
        #  return self.clone_graph_dfs(node)
        return self.clone_graph_dfs_recursive(node)

    def clone_graph_bfs(self, node: "Node") -> "Node":
        if not node: return
        cloned = {node: Node(node.val)}
        queue = deque([node])
        while queue:
            curr = queue.popleft()
            for nb in curr.neighbors:
                if nb not in cloned:
                    cloned[nb] = Node(nb.val)
                    queue.append(nb)
                cloned[curr].neighbors.append(cloned[nb])
        return cloned[node]

    def clone_graph_dfs(self, node: "Node") -> "Node":
        if not node: return
        cloned = {node: Node(node.val)}
        stack = [node]
        while stack:
            curr = stack.pop()
            for nb in curr.neighbors:
                if nb not in cloned:
                    cloned[nb] = Node(nb.val)
                    stack.append(nb)
                cloned[curr].neighbors.append(cloned[nb])
        return cloned[node]

    def clone_graph_dfs_recursive(self, node: "Node") -> "Node":
        cloned = {}
        def clone(curr: "Node") -> "Node":
            cloned[curr] = Node(curr.val)
            cloned[curr].neighbors = list(map(
                lambda nb: cloned[nb] if nb in cloned else clone(nb),
                curr.neighbors
            ))
            return cloned[curr]
        return clone(node) if node else None


nodes = [Node(i) for i in range(4)]
nodes[0].neighbors = [nodes[1], nodes[3]]
nodes[1].neighbors = [nodes[0], nodes[2]]
nodes[2].neighbors = [nodes[1], nodes[3]]
nodes[3].neighbors = [nodes[0], nodes[2]]

cloned = Solution().clone_graph_dfs_recursive(nodes[0])
