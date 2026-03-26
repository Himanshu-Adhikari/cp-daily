# 📅 Daily CP Solutions — 2026-03-26

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg No Of Ways To Arrive At Destination
**Platform:** GeeksforGeeks

Problem Insight:
This solution counts the number of shortest paths from a source node (0) to a target node (V-1) in a weighted, undirected graph with non-negative edge weights. It leverages a modified shortest path algorithm.

Approach:
The solution adapts Dijkstra's algorithm by simultaneously tracking both the shortest distance to each node and the number of distinct shortest paths to reach that distance. When a shorter path is found, the distance and path count are updated. When an equally short path is found, its path count is added to the existing count.

Time Complexity:
O(E log V)
This is due to Dijkstra's algorithm using a binary min-heap priority queue, where E is the number of edges and V is the number of vertices.

Space Complexity:
O(V + E)
This accounts for the adjacency list storing the graph (V+E), and the distance, ways, and priority queue data structures (V each).

Optimization Notes:
The solution is optimal. Dijkstra's algorithm is the standard and most efficient approach for finding shortest paths in graphs with non-negative edge weights, and its modification for path counting does not asymptotically increase its complexity.

CODE:
class Solution:
    def countPaths(self, V, edges):
        # code here
        MOD = 10**9 + 7
        
        adj = [[] for _ in range(V)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        
        dist = [float('inf')] * V
        ways = [0] * V
        dist[0] = 0
        ways[0] = 1
        pq = [(0, 0)]
        while pq:
            d, u = heapq.heappop(pq)
            if d > dist[u]:
                continue
            for v, w in adj[u]:
                if dist[v] > dist[u] + w:
                    dist[v] = dist[u] + w
                    ways[v] = ways[u]
                    heapq.heappush(pq, (dist[v], v))
                elif dist[v] == dist[u] + w:
                    ways[v] = (ways[v] + ways[u]) % MOD
        
        return ways[V - 1] % MOD

### 💻 Implementation
```py
class Solution:
    def countPaths(self, V, edges):
        # code here
        MOD = 10**9 + 7
        
        adj = [[] for _ in range(V)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        
        dist = [float('inf')] * V
        ways = [0] * V
        dist[0] = 0
        ways[0] = 1
        pq = [(0, 0)]
        while pq:
            d, u = heapq.heappop(pq)
            if d > dist[u]:
                continue
            for v, w in adj[u]:
                if dist[v] > dist[u] + w:
                    dist[v] = dist[u] + w
                    ways[v] = ways[u]
                    heapq.heappush(pq, (dist[v], v))
                elif dist[v] == dist[u] + w:
                    ways[v] = (ways[v] + ways[u]) % MOD
        
        return ways[V - 1] % MOD
        
        
```

## 🔹 Leetcode Equal-Sum-Grid-Partition-Ii
**Platform:** LeetCode

Problem Insight:
The problem asks to partition a grid either horizontally or vertically into two subgrids. It seeks to determine if these subgrids can have equal sums, or if their sums can be made equal by moving a single element from the larger subgrid to the smaller one.

Approach:
The solution iterates through all possible horizontal partition lines. For each line, it computes the sum of elements in the top and bottom subgrids. It checks if sums are equal or if a single element from the larger subgrid can be moved to balance the sums. This process is then repeated for vertical partitions by transposing the grid.

Time Complexity: O(MN)
The grid is traversed twice: once for initial sum/frequency calculations and then iterating through M-1 horizontal cuts, each involving iterating N columns. Transposing and the second pass also take O(MN).

Space Complexity: O(MN)
Two frequency maps (defaultdict) are used, which in the worst case could store up to MN distinct elements, requiring O(MN) space.

Optimization Notes:
The core logic for the "one element swap" condition is incorrect; it checks for an element equal to the total difference instead of half the difference. Fixing this would require checking for diff / 2 (and ensuring diff is even). With this correction, the solution would be optimal in time and space complexity as it explores all required partitions and elements.

### 💻 Implementation
```py
class Solution:
   def canPartitionGrid(self, grid):
       return self._solve(grid) or self._solve(list(zip(*grid)))

   def _solve(self, grid):
       m, n = len(grid), len(grid[0])
       total = sum(sum(row) for row in grid)

       bot_freq = defaultdict(int)
       for row in grid:
           for x in row:
               bot_freq[x] += 1

       top_freq = defaultdict(int)
       top_sum = 0

       for i in range(m - 1):
           for j in range(n):
               v = grid[i][j]
               top_sum += v
               top_freq[v] += 1
               bot_freq[v] -= 1

           bot_sum = total - top_sum
           if top_sum == bot_sum:
               return True

           diff = abs(top_sum - bot_sum)
           if top_sum > bot_sum:
               freq, r1, r2 = top_freq, 0, i
           else:
               freq, r1, r2 = bot_freq, i + 1, m - 1

           rows = r2 - r1 + 1
           if rows * n == 1:    
               continue
           elif rows == 1:   
               if grid[r1][0] == diff or grid[r1][n - 1] == diff:
                   return True
           elif n == 1:        
               if grid[r1][0] == diff or grid[r2][0] == diff:
                   return True
           elif freq.get(diff, 0) > 0: 
               return True

       return False
```
