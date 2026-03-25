# 📅 Daily CP Solutions — 2026-03-25

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Minimum Height Trees
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks to find all nodes in a tree such that if any of these nodes are chosen as the root, the resulting tree has the minimum possible height. These are the centers of the tree.

Approach:
The solution uses a leaf-shaving algorithm. It iteratively removes all current leaf nodes from the tree layer by layer, decrementing the degrees of their neighbors, and adding new leaf nodes to a queue until only the tree's true center(s) remain. The final nodes in the queue are the minimum height roots.

Time Complexity:
O(V+E). Each node and edge is processed a constant number of times during graph construction and the iterative leaf removal process.

Space Complexity:
O(V+E). The adjacency list stores the graph, and the degree array and queue store information proportional to the number of nodes.

Optimization Notes:
This solution is optimal. It correctly finds the minimum height roots (tree centers) in linear time, which is the best possible complexity as every node and edge might need to be visited.

### 💻 Implementation
```py
class Solution:
    def minHeightRoot(self, V, edges):
        gr=[[] for i in range(V)]
        ind=[0]*V
        for i in edges:
            gr[i[0]].append(i[1])
            gr[i[1]].append(i[0])
            ind[i[0]]+=1
            ind[i[1]]+=1
        res=[]
        q=[]
        for i in range(V):
            if(ind[i]==1):
                q.append(i)
        while(q):
            res=[]
            s=len(q)
            while(s):
                c=q.pop(0)
                res.append(c)
                for i in gr[c]:
                    ind[i]-=1
                    if(ind[i]==1):
                        q.append(i)
                s-=1
        return res
        

```

## 🔹 Leetcode Equal Sum Grid Partition I
**Platform:** LeetCode

Problem Insight:
The problem asks to determine if a grid can be partitioned into two sub-grids with equal sums, either horizontally (by splitting rows) or vertically (by splitting columns), ensuring both parts are non-empty. This implies the total sum must be even and non-zero.

Approach:
The solution first computes the total sum of the grid. It then iterates through all possible horizontal split points, accumulating the sum of rows from the top and checking if this accumulated sum equals the remaining sum. If no horizontal split is found, it re-initializes and iterates through all possible vertical split points, accumulating column sums from the left and checking for equality.

Time Complexity:
O(M*N)
The solution iterates through all grid cells multiple times: once for the initial total sum, once for horizontal partitions (M rows, N sum per row), and once for vertical partitions (N columns, M sum per column).

Space Complexity:
O(1)
Only a few constant-size variables are used to store sums and dimensions, independent of the grid's size.

Optimization Notes:
The solution is optimal in terms of time and space complexity, as every cell must be visited. A minor improvement would be to calculate the total sum only once at the beginning. Additionally, checking if the total sum is odd allows for an early exit. Using a target sum (total sum / 2) can make the sum comparison logic slightly cleaner.

### 💻 Implementation
```py
class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        sm=sum(sum(i) for i in grid)
        curr=0
        for i in grid:
            curr+=sum(i)
            sm-=sum(i)
            if(curr and sm and curr==sm):return True
        sm=sum(sum(i) for i in grid)
        curr=0
        n=len(grid[0])
        m=len(grid)
        for j in range(n):
            for i in range(m):
                curr+=grid[i][j]
                sm-=grid[i][j]
            if(curr and sm and curr==sm):return True
        return False
```
