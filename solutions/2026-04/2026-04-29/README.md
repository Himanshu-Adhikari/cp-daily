# 📅 Daily CP Solutions — 2026-04-29

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Minimum-Swaps-Required-To-Group-All-1S-Together
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks for the minimum swaps to group all ones together in a contiguous block. This is equivalent to finding a window of size equal to the total number of ones that contains the maximum number of ones.

Approach:
First, count the total number of ones (let this be 'o'). Then, use a sliding window of size 'o' to iterate through the array. For each window, count the number of ones within it. The minimum swaps required is 'o' minus the maximum number of ones found in any window.

Time Complexity:
O(N)
The solution iterates through the array twice (once for sum, once for sliding window), both are linear operations.

Space Complexity:
O(1)
It uses a fixed number of variables regardless of the input array size.

Optimization Notes:
The solution is optimal. It processes each element of the array at most a constant number of times (once for counting ones, once for the sliding window), achieving a linear time complexity which is the best possible as every element must be examined.

### 💻 Implementation
```cpp
class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n=arr.size();
        int o=accumulate(begin(arr),end(arr),0);
        if(o==0)return -1;
        int res=n;
        for(int i=0,j=0,c=0;i<n;i++){
            c+=arr[i];
            if(i-j+1>o)c-=arr[j++];
            res=min(res,o-c);
        }
        return res;
    }
};
```

## 🔹 Leetcode Maximum-Score-From-Grid-Operations
**Platform:** LeetCode

Problem Insight:
The problem involves finding a maximum score by selecting segments in adjacent columns of a grid, where segment choices must satisfy an overlap constraint (one segment contains the other). The scoring function is non-trivial, involving current column scores and specific adjustments based on height differences with the previous column.

Approach:
A dynamic programming approach is used where dp[i][curr_h][prev_h] stores the maximum score considering columns up to 'i', with column 'i' having a segment of height 'curr_h' and column 'i-1' having 'prev_h'. Transitions handle two cases: curr_h <= prev_h (contained) or curr_h > prev_h (containing), with complex score adjustments. Prefix sum arrays are used for efficient segment sum calculation, and prefix/suffix maximum arrays optimize range queries within DP transitions from O(N) to O(1) after O(N) precomputation per column.

Time Complexity:
O(N^3). There are N columns, and for each column, a nested loop iterates N possible 'curr_h' values and N possible 'prev_h' values. The auxiliary prev_max and prev_suffix_max tables are also recomputed in O(N^2) per column, resulting in N * (N^2 + N^2) operations.

Space Complexity:
O(N^3). The main dp table is of size N * (N+1) * (N+1). Auxiliary tables like col_sum, prev_max, and prev_suffix_max are O(N^2), but dp dominates.

Optimization Notes:
The time complexity of O(N^3) is likely optimal for this specific DP state definition given the problem constraints and complex transitions. However, the space complexity can be optimized from O(N^3) to O(N^2). This is achieved by realizing that dp[i] only depends on dp[i-1]. Instead of storing the full N layers of the dp table, only two layers (current and previous) are needed, along with the auxiliary O(N^2) prev_max and prev_suffix_max tables.

### 💻 Implementation
```py
class Solution:
    def maximumScore(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        if n == 1:
            return 0

        dp = [[[0] * (n + 1) for _ in range(n + 1)] for _ in range(n)]
        prev_max = [[0] * (n + 1) for _ in range(n + 1)]
        prev_suffix_max = [[0] * (n + 1) for _ in range(n + 1)]
        col_sum = [[0] * (n + 1) for _ in range(n)]

        for c in range(n):
            for r in range(1, n + 1):
                col_sum[c][r] = col_sum[c][r - 1] + grid[r - 1][c]

        for i in range(1, n):
            for curr_h in range(n + 1):
                for prev_h in range(n + 1):
                    if curr_h <= prev_h:
                        extra_score = col_sum[i][prev_h] - col_sum[i][curr_h]
                        dp[i][curr_h][prev_h] = max(
                            dp[i][curr_h][prev_h],
                            prev_suffix_max[prev_h][0] + extra_score,
                        )
                    else:
                        extra_score = (
                            col_sum[i - 1][curr_h] - col_sum[i - 1][prev_h]
                        )
                        dp[i][curr_h][prev_h] = max(
                            dp[i][curr_h][prev_h],
                            prev_suffix_max[prev_h][curr_h],
                            prev_max[prev_h][curr_h] + extra_score,
                        )

            for curr_h in range(n + 1):
                prev_max[curr_h][0] = dp[i][curr_h][0]
                for prev_h in range(1, n + 1):
                    penalty = (
                        col_sum[i][prev_h] - col_sum[i][curr_h]
                        if prev_h > curr_h
                        else 0
                    )
                    prev_max[curr_h][prev_h] = max(
                        prev_max[curr_h][prev_h - 1],
                        dp[i][curr_h][prev_h] - penalty,
                    )

                prev_suffix_max[curr_h][n] = dp[i][curr_h][n]
                for prev_h in range(n - 1, -1, -1):
                    prev_suffix_max[curr_h][prev_h] = max(
                        prev_suffix_max[curr_h][prev_h + 1],
                        dp[i][curr_h][prev_h],
                    )

        ans = 0
        for k in range(n + 1):
            ans = max(ans, dp[n - 1][n][k], dp[n - 1][0][k])

        return ans
    
```
