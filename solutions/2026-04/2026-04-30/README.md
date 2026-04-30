# 📅 Daily CP Solutions — 2026-04-30

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Does-Array-Represent-Heap
**Platform:** GeeksforGeeks

Problem Insight:
A max-heap requires that every parent node must be greater than or equal to its children. This property needs to be verified for all possible parent-child relationships.

Approach:
The solution iterates through each element in the array, treating it as a potential parent. For each parent, it checks if its left child and right child (if they exist within array bounds) violate the max-heap property. If any child is found to be greater than its parent, it immediately determines that it's not a max-heap. If all checks pass, it concludes it is a max-heap.

Time Complexity:
O(N)
The algorithm iterates through all N elements of the array once, performing constant time comparisons and array accesses for each.

Space Complexity:
O(1)
The solution uses a fixed number of integer variables, independent of the input array size.

Optimization Notes:
The solution is asymptotically optimal. A slight practical optimization could be to iterate only up to index `n/2 - 1`, as elements from `n/2` to `n-1` are leaf nodes and will never have children, making checks for them redundant.

### 💻 Implementation
```cpp

class Solution{
    public:
    bool isMaxHeap(vector<int>&arr)
    {   
        int n=arr.size();
        int l,r;
        for(int i=0;i<n;i++){
             if(2*i+1 < n){
                 l=arr[2*i+1];
                 if(arr[i]<l)return 0;
             }
             if(2*i+2<n){
                 r=arr[2*i+2];
                 if(r>arr[i])return 0;
             }
        }
        return 1;
    }
};

```

## 🔹 Leetcode Maximum-Path-Score-In-A-Grid
**Platform:** LeetCode

Problem Insight:
This problem requires finding a path from the top-left to the bottom-right of a grid that maximizes the sum of values encountered, while adhering to a maximum allowed cost (total count of '1's) along the path. Only down and right movements are permitted.

Approach:
A 3D dynamic programming table dp[i][j][cost] is used to store the maximum sum of values obtained when reaching cell (i, j) with exactly 'cost' incurred. The table is filled iteratively, considering moves from (i, j) to (i+1, j) or (i, j+1), updating the maximum score for reachable states with their respective costs.

Time Complexity:
O(m * n * k)
The solution iterates through m rows, n columns, and k possible costs, performing constant time operations for each state.

Space Complexity:
O(m * n * k)
A 3D DP table of size (m+1) x (n+1) x (k+1) is used to store the maximum scores for all possible states.

Optimization Notes:
The solution is optimal for this problem. The state representation (row, column, current_cost) is essential to track all necessary information for making optimal decisions, and the dynamic programming approach efficiently explores all valid paths within these constraints.

### 💻 Implementation
```cpp
class Solution {
public:
    // int dp[201][201][1001], f = 0;
    // int rec(int i,int j,int k,vector<vector<int>>&a,int m,int n){
    //     if(i>=m || j>=n || k<0 )return 0;
    //     int cst=(a[i][j]?1:0);
    //     if(i==m-1 && j==n-1){
    //         if((k-cst)>=0){
    //             f=0;
    //             dp[i][j][k]=a[i][j];
    //             return dp[i][j][k];
    //         }
    //     }
    //     int f=a[i][j]+rec(i+1,j,k-cst,a,m,n);
    //     int s=a[i][j]+rec(i,1+j,k-cst,a,m,n);
    //     return dp[i][j][k]=max(f,s);
    // }
    int maxPathScore(vector<vector<int>>& a, int k) {
        int m = a.size(), n = a[0].size();
        // memset(dp, -1, sizeof(dp));
        // f = 0;
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        int cst = (a[0][0] ? 1 : 0);
        if (cst <= k)
            dp[0][0][cst] = a[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int p = 0; p <= k; p++) {
                    cst = (a[i][j] ? 1 : 0);
                    if (dp[i][j][p] == -1) continue;
                    if (i < m - 1 and (p + (a[i + 1][j] ? 1 : 0)) <= k) {
                        dp[i + 1][j][p + (a[i + 1][j] ? 1 : 0)] =
                            max(dp[i + 1][j][p + (a[i + 1][j] ? 1 : 0)],
                                dp[i][j][p] + a[i+1][j]);
                    }
                    if (j < n - 1 and (p + (a[i][j + 1] ? 1 : 0)) <= k) {
                        dp[i][j + 1][p + (a[i][1 + j] ? 1 : 0)] =
                            max(dp[i][1 + j][p + (a[i][1 + j] ? 1 : 0)],
                                dp[i][j][p] + a[i][j+1]);
                    }
                }
            }
        }
    
    int res = -1;
    for (int i = 0; i <= k; i++) {
        res = max(res, dp[m - 1][n - 1][i]);
    }
    return res;
}
}
;
```
