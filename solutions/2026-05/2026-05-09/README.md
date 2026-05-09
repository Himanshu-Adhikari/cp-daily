# 📅 Daily CP Solutions — 2026-05-09

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Total No Of Spanning Trees In A Graph
**Platform:** GeeksforGeeks

Problem Insight:
The problem aims to count the total number of spanning trees in a given graph. This is a fundamental problem in graph theory.

Approach:
The solution implements Kirchhoff's Matrix Tree Theorem. It constructs the graph's Laplacian matrix, then computes the determinant of any of its (N-1) x (N-1) principal minors, which yields the number of spanning trees.

Time Complexity:
O(N^3)
Constructing the Laplacian matrix is O(N+M), but computing the determinant of an N x N matrix dominates with O(N^3) using standard methods like Gaussian elimination.

Space Complexity:
O(N^2)
The Laplacian matrix L of size N x N requires O(N^2) space to store its elements.

Optimization Notes:
This approach is optimal for dense graphs when using general determinant algorithms. For extremely large N, or if the graph is sparse, specialized determinant computation over integers (to avoid floating-point precision issues with numpy.linalg.det) or specific Matrix Tree Theorem implementations might be preferred.

### 💻 Implementation
```py
import numpy as np

class Solution:
    def countSpanTree(self, n, edges):
        L = np.zeros((n, n), dtype=int)
        for u, v in edges:
            L[u][u] += 1
            L[v][v] += 1
            L[u][v] -= 1
            L[v][u] -= 1
        minor = L[:-1, :-1]
        return round(np.linalg.det(minor))
```

## 🔹 Leetcode Cyclically-Rotating-A-Grid
**Platform:** LeetCode

Problem Insight:
The problem requires rotating each concentric layer of a 2D grid independently by a given number of steps, k. Each layer's elements are rotated as if they form a 1D array.

Approach:
The solution iterates through concentric layers of the grid, from the outermost to the innermost. For each layer, it extracts all elements into a temporary 1D vector, applies the k-step rotation to this 1D vector using modulo arithmetic, and then places the rotated elements back into their respective positions within the grid layer.

Time Complexity:
O(N*M)
Each element of the N x M grid is visited a constant number of times (extracted and placed back).

Space Complexity:
O(N+M)
A temporary vector stores elements of one grid layer at a time, with the largest layer having O(N+M) elements.

Optimization Notes:
The solution is optimal in terms of time complexity as every element in the grid must be visited to be rotated. While it uses O(N+M) auxiliary space, which could theoretically be O(1) with complex in-place swaps, the current approach is practically optimal and simpler to implement without affecting the dominant time complexity.

### 💻 Implementation
```cpp
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k)
    {
        int n=grid.size();
        int m=grid[0].size();
        int R1=0,C1=0,R2=n-1,C2=m-1;
        while(R1<R2 && C1<C2)
        {
            vector<int>res;
            for (int j=C1;j<=C2;j++)res.push_back(grid[R1][j]);
            for (int i=R1+1;i<=R2;i++)res.push_back(grid[i][C2]);
            for (int j=C2-1;j>=C1;j--)res.push_back(grid[R2][j]);
            for (int i=R2-1;i>=R1+1;i--)res.push_back(grid[i][C1]);
           int r=0,mn=res.size();
            for (int j=C1;j<=C2;j++)grid[R1][j]=res[((r++)+k)%mn];
            for (int i=R1+1;i<=R2;i++)grid[i][C2]=res[((r++)+k)%mn];
            for (int i=C2-1;i>=C1;i--)grid[R2][i]=res[((r++)+k)%mn];
            for (int i=R2-1;i>=R1+1;i--)grid[i][C1]=res[((r++)+k)%mn];
            R1++;C1++;R2--;C2--;
        }
        return grid;

    }
};

```
