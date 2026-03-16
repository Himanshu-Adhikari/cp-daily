# 📅 Daily CP Solutions — 2026-03-16

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg K Sum Path
**Platform:** GeeksforGeeks

Problem Insight:
This problem counts paths in a binary tree that sum to a target value K, where paths can start and end at any node. It requires efficiently identifying subpaths using prefix sums.

Approach:
A Depth First Search (DFS) traverses the tree while maintaining a running prefix sum from the root. A hash map stores the frequency of encountered prefix sums. For each node, it checks if current_sum - K exists in the map, contributing to the total count, then updates and backtracks the map.

Time Complexity: O(N log N)
Each of N nodes is visited once, and map operations (insert, lookup, delete) take O(log S) where S is the number of distinct prefix sums, up to N.

Space Complexity: O(N)
The map can store up to N distinct prefix sums, and the recursion stack depth can be up to N in a skewed tree.

Optimization Notes:
The approach is generally optimal for this problem type. Using std::unordered_map instead of std::map could reduce average-case time complexity to O(N).

### 💻 Implementation
```cpp
class Solution {
  public:
        #define ll long long
        map<ll,ll>m;
    ll rec(ll sm,int k,Node*rt){
        if(!rt)return 0;
        sm+=rt->data;
        ll res=m[sm-k];
        m[sm]++;
        res+=rec(sm,k,rt->left);
        res+=rec(sm,k,rt->right);
        m[sm]--;
        return res;
    }
    int countAllPaths(Node *root, int k) {
        m[0]=1;
        return rec(0,k,root);
    }
};
```

## 🔹 Leetcode Get Biggest 3 Rhombus Sum In Matrix
**Platform:** LeetCode

Problem Insight:
The problem requires finding the top three largest distinct sums of numbers within rhombus shapes (including single cells) in a given 2D grid.

Approach:
The solution iterates through every cell in the grid as a potential center for a rhombus. For each center, it expands outwards, calculating sums for rhombuses of increasing radius. Each calculated sum is added to a set to ensure distinctness. Finally, the set of sums is sorted in descending order, and the top three are returned.

Time Complexity:
O(N * M * min(N,M)^2)
There are N*M possible centers. For each center, the algorithm iterates through possible rhombus radii k (up to min(N,M)/2). Calculating the sum for each rhombus of radius k involves traversing 4 segments, each of length k, leading to O(k) operations. Thus, for each center, the sum calculation takes O(sum_k k) = O(min(N,M)^2) time.

Space Complexity:
O(N * M * min(N,M))
The set 's' stores all unique rhombus sums. In the worst case, it can contain up to N*M*min(N,M) distinct sums (though typically fewer are unique). Each sum is an integer.

Optimization Notes:
The current solution is not optimal. The main inefficiency is recalculating the entire rhombus sum from scratch for each increasing radius k. This can be significantly optimized. One common approach is to use 2D diagonal prefix sums to compute the sum of any diagonal segment in O(1). With this precomputation (O(N*M)), each rhombus sum can be calculated in O(1) time. This would reduce the overall time complexity to O(N * M * min(N,M)), which is much more efficient.

### 💻 Implementation
```py
class Solution:
    def getBiggestThree(self, g: List[List[int]]) -> List[int]:
        n,m=len(g),len(g[0])
        s=set()
        for i in range(n):
            for j in range(m):
                s.add(g[i][j])
                k=1
                while i-k>=0 and i+k<n and j-k>=0 and j+k<m:
                    x=i-k;y=j;t=0
                    for d in range(k): t+=g[x+d][y+d]
                    x=i;y=j+k
                    for d in range(k): t+=g[x+d][y-d]
                    x=i+k;y=j
                    for d in range(k): t+=g[x-d][y-d]
                    x=i;y=j-k
                    for d in range(k): t+=g[x-d][y+d]
                    s.add(t)
                    k+=1
        return sorted(s,reverse=True)[:3]
```
