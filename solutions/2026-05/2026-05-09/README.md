# 📅 Daily CP Solutions — 2026-05-09

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Total No Of Spanning Trees In A Graph
**Platform:** GeeksforGeeks

Problem Insight:
This solution counts the number of spanning trees in a given graph. It applies Kirchhoff's Matrix Tree Theorem, a fundamental result in graph theory.

Approach:
The core idea is to construct the Laplacian matrix of the graph. A cofactor is then obtained by removing any single row and column from the Laplacian matrix. The determinant of this cofactor yields the total count of spanning trees.

Time Complexity:
O(n^3)
Constructing the Laplacian matrix takes O(n^2 + E) time, and calculating the determinant of an (n-1)x(n-1) matrix dominates at O(n^3).

Space Complexity:
O(n^2)
The solution requires O(n^2) space to store the n x n Laplacian matrix and its minor.

Optimization Notes:
The approach is generally optimal for counting spanning trees in arbitrary graphs using the Matrix Tree Theorem. For competitive programming, if the answer needs to be very large, floating point precision issues from numpy.linalg.det and rounding might arise, requiring specialized integer determinant calculation or modular arithmetic if a modulo is specified.

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
The problem requires rotating elements within concentric layers of a 2D grid. Each layer is treated as a separate circular array that undergoes a left rotation.

Approach:
The solution iterates through concentric layers of the grid from outermost to innermost. For each layer, it extracts all elements into a temporary 1D vector. It then calculates the new position of each element after k rotations using modulo arithmetic and places them back into the grid along the same layer.

Time Complexity:
O(N*M)
Each element in the grid is visited a constant number of times (once to extract, once to place back) across all layer iterations.

Space Complexity:
O(N+M)
The auxiliary space is used by the 'res' vector, which stores elements of the current layer. In the worst case (outermost layer), its size is proportional to 2*(N+M).

Optimization Notes:
The solution is optimal in terms of time complexity because every element must be visited at least once. The space complexity is also optimal for this type of approach, as temporary storage for at least one layer's elements is generally needed to perform the rotation effectively.

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
