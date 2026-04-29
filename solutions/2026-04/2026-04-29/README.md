# 📅 Daily CP Solutions — 2026-04-29

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Minimum-Swaps-Required-To-Group-All-1S-Together
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks for the minimum swaps to group all 1s contiguously. This is equivalent to finding a contiguous subarray (window) of length equal to the total number of 1s that contains the maximum possible count of 1s.

Approach:
First, count the total number of 1s in the array. Then, use a fixed-size sliding window, with its size equal to the total 1s count, to iterate through the array. For each window, count the number of 1s it contains. The minimum swaps required is the total 1s minus the maximum 1s found in any such window.

Time Complexity:
O(N) because the array is traversed once to sum the 1s and then once more using a sliding window, processing each element a constant number of times.

Space Complexity:
O(1) because the solution only uses a few constant extra variables regardless of the input array size.

Optimization Notes:
This solution is optimal as it achieves linear time complexity, which is the theoretical minimum to examine all elements, and uses constant additional space. The specific return value of -1 for arrays with no 1s should be confirmed against the problem statement.

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
This appears to be a dynamic programming problem on a grid, likely involving selecting segments from columns to maximize a score. The score calculation depends on segment lengths and relative positions between adjacent columns.

Approach:
The solution uses a 3D dynamic programming approach where dp[i][curr_h][prev_h] stores the maximum score up to column 'i', with column 'i' having segment height 'curr_h' and column 'i-1' having segment height 'prev_h'. Prefix sums for columns are precomputed. Transitions are optimized using prefix/suffix maximums on the previous DP layer.

Time Complexity:
O(N^3)
The solution iterates through N columns, and for each column, it calculates (N+1)*(N+1) DP states.

Space Complexity:
O(N^3)
The 3D dp array dp[N][N+1][N+1] dominates the space complexity.

Optimization Notes:
The space complexity can be optimized from O(N^3) to O(N^2) by noticing that dp[i] only depends on dp[i-1]. Only two layers of the dp table (current and previous column) are needed at any time.

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
