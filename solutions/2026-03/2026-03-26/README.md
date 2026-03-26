# 📅 Daily CP Solutions — 2026-03-26

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg No Of Ways To Arrive At Destination
**Platform:** GeeksforGeeks

Problem Insight:
This problem asks to find the number of distinct shortest paths from a source node to a destination node in a weighted undirected graph with non-negative edge weights. It's a variation of the shortest path problem.

Approach:
The solution extends Dijkstra's algorithm. It maintains both the shortest distance to each node (dist array) and the count of shortest paths to each node (ways array). When a shorter path to a node is found, its distance and ways are updated. When an equally short path is found, the ways count is incremented by the ways from the current node. Modulo arithmetic is applied to prevent overflow.

Time Complexity:
O((V+E) log V)
This is due to Dijkstra's algorithm using a min-priority queue, where V is the number of vertices and E is the number of edges. Each vertex is extracted once, and each edge relaxation involves a potential priority queue operation.

Space Complexity:
O(V + E)
This is for storing the adjacency list representation of the graph, the distance array, the ways array, and the priority queue.

Optimization Notes:
The solution is optimal. For graphs with non-negative edge weights, Dijkstra's algorithm is the most efficient known single-source shortest path algorithm, and this solution correctly adapts it to count paths without increasing its asymptotic complexity. The space complexity is also optimal as it requires storing the graph and auxiliary information.

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
The problem asks if a 2D grid can be partitioned into two contiguous subgrids (horizontally or vertically) such that their sums are equal. An additional condition allows for balancing unequal sums by changing a single element in the larger-sum subgrid to zero, with specific rules on which element can be changed based on the subgrid dimensions.

Approach:
The solution first calculates the total sum of the grid. It then iterates through all possible horizontal cut points, forming a top and bottom subgrid. For each partition, it checks if their sums are equal. If not, it identifies the difference and the larger-sum subgrid. It then applies specific rules to check if an element within that subgrid can be changed to zero to balance the sums. The entire process is repeated after transposing the grid to handle vertical partitions.

Time Complexity:
O(M*N)
The initial sum and frequency map construction take O(M*N). The loop iterates M times, and inside, each column's elements are processed (N operations), leading to O(M*N). Transposing the grid also takes O(M*N).

Space Complexity:
O(M*N)
Frequency maps (bot_freq, top_freq) can store up to M*N distinct elements in the worst case. The transposed grid created by list(zip(*grid)) also takes O(M*N) space.

Optimization Notes:
The solution is optimal in terms of time complexity, as it must examine all elements and all possible contiguous cuts (O(M*N)). The space complexity for frequency maps is also optimal given the requirement to track element counts for potential modifications. The specific conditions for which elements can be modified (e.g., only boundary elements for single-row/column subgrids, any element otherwise) are unique to this problem's implied rules; assuming these rules are correct, the code implements them efficiently.

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
