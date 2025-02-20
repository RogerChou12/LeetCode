"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        # Breadth-First Search
        if not node: # empty graph
            return node
        # bfs search for nodes
        bfs = deque([node])
        # store copy graph node as dictionary
        clone_graph = {node.val:Node(node.val, [])}
        while bfs:
            current = bfs.popleft()
            current_clone = clone_graph[current.val]
            for nei in current.neighbors:
                if nei.val not in clone_graph: # neighbor is not cloned and visited
                    clone_graph[nei.val] = Node(nei.val, []) # clone it
                    bfs.append(nei) # add to 'bfs' for next searching
                current_clone.neighbors.append(clone_graph[nei.val])
        return clone_graph[node.val]