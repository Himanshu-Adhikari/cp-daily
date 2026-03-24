# 📅 Daily CP Solutions — 2026-03-24

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Course Schedule 1
**Platform:** GeeksforGeeks

Problem Insight:
Determining if a set of courses with prerequisites can be completed is equivalent to detecting cycles in a directed graph.

Approach:
The solution uses Kahn's algorithm (topological sort). It computes the in-degree of each course and initializes a queue with courses having zero in-degrees. It then iteratively processes courses from the queue, decrementing the in-degree of their dependent courses. If a dependent course's in-degree drops to zero, it's added to the queue. If all courses are eventually processed this way, no cycle exists, and all courses can be finished.

Time Complexity:
O(N + P)
Each course and prerequisite is processed a constant number of times for building the graph and during the BFS traversal.

Space Complexity:
O(N + P)
Storing in-degrees (vector 'a'), adjacency list (map 'm'), and the queue 'q' takes space proportional to the number of courses and prerequisites.

Optimization Notes:
The solution is optimal in terms of asymptotic time complexity, O(N+P), as it correctly implements Kahn's algorithm. A minor optimization could be to use a vector of vectors for the adjacency list instead of a map to potentially improve constant factors for graph construction.

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
The problem asks to calculate the product of all elements in a 2D grid except for the current cell's value, for every cell, with all operations performed modulo a given constant. This is a 2D extension of the classic "product of array except self" problem.

Approach:
The solution first flattens the 2D grid into a 1D vector, applying the modulo operation to each element. It then computes prefix products and suffix products for this 1D vector. For each element at index i, the product of all other elements is found by multiplying the prefix product up to i-1 and the suffix product from i+1. These 1D results are then mapped back to form the 2D output matrix, ensuring all intermediate and final products are taken modulo 12345.

Time Complexity:
O(R*C)
Justification: The flattening, prefix product calculation, suffix product calculation, and final result matrix construction each iterate through all R*C elements once.

Space Complexity:
O(R*C)
Justification: Auxiliary 1D vectors 't', 'pre', and 'suf' are used, each storing R*C elements. The result matrix 'res' also takes O(R*C) space.

Optimization Notes:
The solution is optimal. It requires processing each element a constant number of times and uses auxiliary space proportional to the input size for storing prefix and suffix products, which is standard for this type of problem. Achieving O(1) auxiliary space (beyond the output matrix) is possible for a 1D array, but typically involves more complex logic for the 2D case or if the input array cannot be modified.

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
