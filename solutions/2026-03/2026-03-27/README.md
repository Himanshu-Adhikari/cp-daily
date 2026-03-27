# 📅 Daily CP Solutions — 2026-03-27

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Chocolate Pickup
**Platform:** GeeksforGeeks

Problem Insight:
This problem involves two robots moving simultaneously down a grid, collecting chocolates from their current cells. The goal is to maximize the total chocolates collected without double-counting when robots are on the same cell.

Approach:
The solution uses dynamic programming with memoization. The state is defined by (current row, robot1_column, robot2_column). From each state, it recursively explores all nine possible next positions (3 moves for robot1, 3 for robot2) in the subsequent row, taking the maximum, and adds chocolates from the current cells.

Time Complexity:
O(N * M^2)
There are N * M * M possible states, and each state involves 9 constant-time recursive calls.

Space Complexity:
O(N * M^2)
The memoization dictionary stores a value for each of the N * M * M states.

Optimization Notes:
The approach of using dynamic programming with a state (row, col1, col2) is optimal for this problem, as any path involves these coordinates. The time and space complexities are the best achievable for this state representation. A minor bug exists in the base case where x<=0 incorrectly marks column 0 as out of bounds; it should be x<0.

### 💻 Implementation
```py
class Solution:
    def maxChocolate(self, grid):
        n,m=len(grid),len(grid[0])
        memo={}
        def rec(i,j,x):
            if(i>=n or j<0 or j>=m or x<=0 or x>=m):return 0
            ky=tuple([i,j,x])
            if(ky in memo):return memo[ky]
            res=0
            for q in range(-1,2):
                for r in range(-1,2):
                   res=max(res,rec(i+1,j+q,r+x))
            res+=grid[i][j]
            if(j!=x):res+=grid[i][x]
            memo[ky]=res
            return res
        return rec(0,0,m-1)
```

## 🔹 Leetcode Matrix-Similarity-After-Cyclic-Shifts
**Platform:** LeetCode

Problem Insight:
The solution checks if the matrix remains identical to its original state after applying a cyclic right shift of k positions to every row. The effective shift k is reduced modulo the number of columns.

Approach:
The solution first normalizes the shift amount k modulo the number of columns. Then, it iterates through each cell in the matrix, comparing mat[i][j] with the value mat[i][(j+k)%m]. If any comparison yields a mismatch, the matrix is not similar, and False is returned immediately. If all comparisons pass, True is returned.

Time Complexity: O(N*M)
The solution iterates through all N rows and M columns of the matrix once.

Space Complexity: O(1)
The solution uses a constant amount of extra space for variables regardless of input size.

Optimization Notes:
This solution is optimal in terms of time complexity. It must inspect every element of the matrix in the worst case to verify the similarity condition across all cells, making O(N*M) unavoidable. The modulo operation for k is already present.

### 💻 Implementation
```py
class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        n,m=len(mat),len(mat[0])
        k=k%m
        res=True
        for i in range(n):
            for j in range(m):
                if(mat[i][j]!=mat[i][(j+k)%m]):return False
        return True
```
