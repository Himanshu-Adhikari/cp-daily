# 📅 Daily CP Solutions — 2026-04-26

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Common Elements
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires finding all unique common elements present in three given sorted arrays. The sorted property of the input is key to an efficient solution.

Approach:
The solution uses a three-pointer approach, one for each array, iterating simultaneously. Pointers are advanced for the array(s) with the smallest current element until all three point to equal values, which are then added to the result, while skipping duplicates.

Time Complexity:
O(N + M + P) where N, M, P are the lengths of arrays a, b, c respectively.
Each pointer traverses its respective array at most once.

Space Complexity:
O(K) where K is the number of common elements.
The space is used to store the result vector, which can be up to the size of the smallest input array in the worst case.

Optimization Notes:
This solution is optimal for finding common elements in three sorted arrays. The three-pointer approach achieves linear time complexity, which is the best possible as every element may need to be examined.

### 💻 Implementation
```cpp
class Solution {
public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int i = 0, j = 0, k = 0;
        vector<int> res;

        while (i < a.size() && j < b.size() && k < c.size()) {
            if (a[i] == b[j] && b[j] == c[k]) {
                if (res.empty() || res.back() != a[i])
                    res.push_back(a[i]);
                i++; j++; k++;
            }
            else if (a[i] < b[j]) {
                i++;
            }
            else if (b[j] < c[k]) {
                j++;
            }
            else {
                k++;
            }
        }
        return res;
    }
};
```

## 🔹 Leetcode Detect-Cycles-In-2D-Grid
**Platform:** LeetCode

Problem Insight:
The goal is to find if there is a cycle of connected cells containing the same character in a grid, where a valid cycle must have a length of at least 4.

Approach:
The solution uses Depth First Search (DFS) to traverse the grid. For each unvisited cell, a DFS is initiated, keeping track of visited cells and the parent in the traversal. A cycle is detected if DFS encounters an already visited neighbor that is not its immediate parent.

Time Complexity:
O(M*N)
Each cell and its four adjacent edges are visited and processed at most once during the DFS traversal.

Space Complexity:
O(M*N)
The 'vis' array stores visited status for all M*N cells, and the DFS recursion stack can go up to M*N in the worst case.

Optimization Notes:
The solution is optimal. Detecting cycles in a grid graph fundamentally requires inspecting all cells and their connections, which takes O(M*N) time. The space complexity is also optimal for storing visited states and the recursion stack.

### 💻 Implementation
```cpp
class Solution {
public:
    int m, n;
    vector<vector<char>> grid;
    int vis[501][501] = {0};
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int nx, ny;
    bool rec(int i, int j, int pi, int pj, char& c) {
        vis[i][j] = 1;
        for (auto d:dir){
            nx=i+d[0],ny=j+d[1];
            if(nx<0 or ny<0 or nx>=m or ny>=n or grid[nx][ny]!=c)continue;
            if(!vis[nx][ny]){
                if(rec(nx,ny,i,j,c))return true;;
            }
            else if(pi!=-1 and pj!=-1 and (nx!=pi or ny!=pj)){
                // cout<<nx<<" "<<ny<<endl;
                // cout<<pi<<" "<<pj<<endl;
                return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        this->grid = grid;
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (rec(i, j, -1, -1, grid[i][j])){
                        // cout<<grid[i][j]<<" ";
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

```
