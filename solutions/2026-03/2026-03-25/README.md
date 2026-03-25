# 📅 Daily CP Solutions — 2026-03-25

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Minimum Height Trees
**Platform:** GeeksforGeeks

Problem Insight:
Finding the minimum height roots in a tree is equivalent to finding its center(s). This can be achieved by iteratively removing all current leaf nodes from the tree.

Approach:
The solution initializes a graph and node degrees. It then adds all initial leaf nodes (degree 1) to a queue. It performs a BFS-like process, iteratively removing layers of leaves. For each removed leaf, it decrements its neighbors' degrees, adding any newly formed leaves to the queue. The nodes remaining in the final iteration are the MHT roots.

Time Complexity:
O(V + E)
Building the graph and the BFS-like traversal each visit every node and edge at most once.

Space Complexity:
O(V + E)
The adjacency list stores O(V+E) connections. The degree array and queue take O(V) space.

Optimization Notes:
The solution is optimal. For a tree, E = V-1, so the complexity is effectively O(V). It processes each node and edge a constant number of times, which is the best possible for this problem.

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
The problem asks if a grid can be partitioned into two non-empty parts with equal sums, either by a single horizontal cut or a single vertical cut.

Approach:
First, calculate the total sum of all elements in the grid. Then, iterate through all possible horizontal cuts, checking if the sum of elements above the cut equals the sum of elements below. If no horizontal cut works, iterate through all possible vertical cuts, checking if the sum of elements to the left of the cut equals the sum of elements to the right. Return True if any such valid partition is found, otherwise False.

Time Complexity:
O(M*N)
The solution iterates through all grid cells a constant number of times to calculate sums for both horizontal and vertical partitions.

Space Complexity:
O(1)
The solution uses a fixed number of variables regardless of the input grid's size.

Optimization Notes:
The solution is optimal in terms of time complexity O(M*N) as every element must be processed. An optimization could be to check if the total sum of the grid is odd at the beginning; if so, an equal partition is impossible, allowing an early return.

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
