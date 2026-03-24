# 📅 Daily CP Solutions — 2026-03-24

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Course Schedule 1
**Platform:** GeeksforGeeks

Problem Insight:
This problem asks to determine if a valid course schedule exists given prerequisites, which translates to detecting cycles in a directed graph.

Approach:
The solution implements Kahn's algorithm for topological sort. It tracks indegrees of courses and uses a queue to process courses with no outstanding prerequisites. If all courses can be processed, no cycle exists.

Time Complexity:
O(V + E)
Where V is the number of courses (n) and E is the number of prerequisites. Each node and edge is processed a constant number of times.

Space Complexity:
O(V + E)
Stores indegrees (V), the queue (V), and the adjacency list (V + E).

Optimization Notes:
The solution is optimal in terms of Big-O complexity for this problem. Using a vector of vectors for the adjacency list instead of a map could slightly improve constant factors.

### 💻 Implementation
```cpp
class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        queue<int>q;
        vector<int>a(n,0);
        map<int,vector<int>>m;
        for(auto c:prerequisites){a[c[1]]++;m[c[0]].push_back(c[1]);}
        for(int i=0;i<n;i++){
            if(!a[i])q.push(i);
        }
        while(!q.empty()){
            int c=q.front();q.pop();
            for(auto d:m[c]){
                a[d]--;
                if(a[d]==0){
                    q.push(d);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(a[i])return false;
        }
        return true;
    }
};
```

## 🔹 Leetcode Construct Product Matrix
**Platform:** LeetCode

Problem Insight:
The problem asks for a matrix where each cell (i,j) contains the product of all other elements in the grid, modulo 12345.

Approach:
The grid is flattened into a 1D array. Prefix products and suffix products are computed for this 1D array, all modulo 12345. For each element at index k in the 1D array, its corresponding result is the product of prefix product up to k-1 and suffix product from k+1, modulo 12345. These results are then mapped back to the 2D output matrix.

Time Complexity:
O(rows * cols)
Flattening, prefix products, suffix products, and mapping back all take linear time with respect to the total number of elements.

Space Complexity:
O(rows * cols)
Auxiliary arrays 't', 'pre', and 'suf' are created, each storing a number of elements proportional to the total grid size.

Optimization Notes:
The solution is optimal in terms of time complexity as every element in the input grid must be processed. It is also optimal in space complexity because auxiliary arrays are a standard and efficient way to store intermediate prefix/suffix products without re-calculating for each element, which would lead to a higher time complexity.

### 💻 Implementation
```cpp
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = 12345;
        int rows = grid.size();
        int cols = grid[0].size();
        int n = rows * cols;
        
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        vector<int> t;
        
        for (auto row : grid) {
            for (auto val : row) {
                t.push_back(val % m);
            }
        }
        
        vector<int> pre(n, 1), suf(n, 1);
        
        for (int i = 1; i < n; i++) {
            pre[i] = (pre[i - 1] * t[i - 1]) % m;
        }
        
        int c = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = (c * suf[i]) % m;
            c = (c * t[i]) % m;
        }
        
        int r = 0; c = 0;
        
        for (int i = 0; i < n; i++) {
            res[r][c] = (pre[i] * suf[i]) % m;
            c++;
            if (c == cols) {
                r++;
                c = 0;
            }
        }
        
        return res;
    }
};

```
