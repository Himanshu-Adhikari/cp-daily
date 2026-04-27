# 📅 Daily CP Solutions — 2026-04-27

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Smallest-Window-Containing-0-1-And-2
**Platform:** GeeksforGeeks

Problem Insight:
This problem asks for the shortest substring that contains all specified distinct characters ('0', '1', '2').
It is a classic application of the sliding window technique.

Approach:
A two-pointer sliding window is used. The 'hi' pointer expands the window, and once the window contains all required characters, the 'lo' pointer contracts it from the left to find the minimum valid length.

Time Complexity:
O(N)
Each character is processed at most twice (once by 'hi' and once by 'lo').

Space Complexity:
O(1)
A fixed-size frequency array of 3 elements is used, independent of input size.

Optimization Notes:
The solution is optimal. It processes each character in the string a constant number of times, achieving linear time complexity which is the lower bound for this problem.

### 💻 Implementation
```cpp
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        // int ans=1e9;
     vector<int> A(3, 0);
        int hi=0, lo=0, n=s.size(), ans=1e9;
        while(hi<n) {
            A[s[hi]-'0']++;
            while(A[0]&&A[1]&&A[2]) {
                ans=min(ans, hi-lo+1);
                A[s[lo++]-'0']--;
            }
            hi++;
        }
        return ans==1e9?-1:ans;
    }
};


```

## 🔹 Leetcode Check-If-There-Is-A-Valid-Path-In-A-Grid
**Platform:** LeetCode

Problem Insight:
This is a graph connectivity problem where grid cells are nodes and valid street connections are edges. A path exists if the start and end cells are connected through valid street segments.

Approach:
The solution uses a Disjoint Set Union (DSU) to track connected components of grid cells. For each cell, it checks valid bidirectional street connections with neighbors and merges connected cells into the same set. Finally, it checks if the start and end cells are in the same set.

Time Complexity:
O(m * n * alpha(m * n))
Each of the m*n cells performs a constant number of DSU find/merge operations, which are amortized O(alpha(N)) with path compression.

Space Complexity:
O(m * n)
The DisjointSet parent array stores m*n elements to represent the connections between grid cells.

Optimization Notes:
The solution employs path compression in the DSU's find operation. However, it lacks union by rank or size in the merge operation, which would further optimize the DSU to achieve the theoretical amortized O(alpha(N)) complexity per operation.

### 💻 Implementation
```py
class Solution:
    class DisjointSet:
        def __init__(self, n):
            self.f = list(range(n))

        def find(self, x):
            if x == self.f[x]:
                return x
            self.f[x] = self.find(self.f[x])
            return self.f[x]

        def merge(self, x, y):
            self.f[self.find(x)] = self.find(y)

    def hasValidPath(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        ds = Solution.DisjointSet(m * n)

        def getId(x, y):
            return x * n + y

        def detectL(x, y):
            if y - 1 >= 0 and grid[x][y - 1] in [1, 4, 6]:
                ds.merge(getId(x, y), getId(x, y - 1))

        def detectR(x, y):
            if y + 1 < n and grid[x][y + 1] in [1, 3, 5]:
                ds.merge(getId(x, y), getId(x, y + 1))

        def detectU(x, y):
            if x - 1 >= 0 and grid[x - 1][y] in [2, 3, 4]:
                ds.merge(getId(x, y), getId(x - 1, y))

        def detectD(x, y):
            if x + 1 < m and grid[x + 1][y] in [2, 5, 6]:
                ds.merge(getId(x, y), getId(x + 1, y))

        def handler(x, y):
            if grid[x][y] == 1:
                detectL(x, y)
                detectR(x, y)
            elif grid[x][y] == 2:
                detectU(x, y)
                detectD(x, y)
            elif grid[x][y] == 3:
                detectL(x, y)
                detectD(x, y)
            elif grid[x][y] == 4:
                detectR(x, y)
                detectD(x, y)
            elif grid[x][y] == 5:
                detectL(x, y)
                detectU(x, y)
            else:
                detectR(x, y)
                detectU(x, y)

        for i in range(m):
            for j in range(n):
                handler(i, j)

        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1))
```
