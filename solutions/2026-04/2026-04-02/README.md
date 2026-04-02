# 📅 Daily CP Solutions — 2026-04-02

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Painting-The-Fence
**Platform:** GeeksforGeeks

Problem Insight:
This problem is a dynamic programming task focused on counting valid colorings of a fence. The core constraint is preventing three or more consecutive posts from having the same color.

Approach:
The solution uses dynamic programming with O(1) space, tracking two states for each post: the number of ways the current post has the same color as the previous one, and the number of ways it has a different color. These states are iteratively updated from post 2 to N.

Time Complexity:
O(N) because the solution iterates through the posts from 3 to N once.

Space Complexity:
O(1) because it only uses a few constant-sized variables to store the current and previous DP states.

Optimization Notes:
The solution is optimal. It solves the problem in linear time using constant extra space, which is the most efficient possible complexity for this problem.

### 💻 Implementation
```py
class Solution {
  public:
    long long countWays(int n, int k) {
        const long long mod = 1e9 + 7;
        
        if (n == 1) return k;
        
        long long same = k;
        long long diff = 1LL * k * (k - 1) % mod;
        
        for (int i = 3; i <= n; i++) {
            long long total = (same + diff) % mod;
            same = diff;
            diff = total * (k - 1) % mod;
        }
        
        return (same + diff) % mod;
    }
};
```

## 🔹 Leetcode Maximum-Amount-Of-Money-Robot-Can-Earn
**Platform:** LeetCode

Problem Insight:
This problem aims to find the maximum sum along a path from the top-left to the bottom-right of a grid, with a limited number of 'powers' to effectively nullify negative coin values.

Approach:
The solution uses recursive dynamic programming with memoization. The state is defined by the current grid coordinates (i, j) and the remaining power (pw). For each cell, it recursively calculates the maximum sum by moving down or right. If a negative coin is encountered and power is available, it considers two options: collecting the coin as is, or using a power to treat its value as zero.

Time Complexity:
O(N * M)
There are N * M cells and 3 possible power states (0, 1, 2), creating N * M * 3 unique DP states. Each state computation involves constant time operations.

Space Complexity:
O(N * M)
The DP table requires O(N * M * 3) space to store computed results. The recursion stack depth is at most O(N + M), which is dominated by the DP table size.

Optimization Notes:
The time and space complexity are optimal for this problem type. However, there is a logical flaw in the calculation for using a power on a negative coin. When a power is used, the current coin's value should be treated as 0 for that specific path branch. The current code incorrectly includes the negative coin's value in one path calculation and then compares it against a future path sum that should have had 0 added for the current cell. The two options (collecting negative coin vs. using power to make it 0) need to be formed correctly before taking their maximum.

### 💻 Implementation
```py
class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        n=len(coins)
        m=len(coins[0])
        dp = [[[None]*3 for _ in range(m)] for _ in range(n)] 
        def rec(i,j,pw):
            if (i<0 or j<0 or i>=n or j>=m):return -float('inf')
            if(i==n-1 and j==m-1):
                if(coins[i][j]<0 and pw>0):
                    return 0
                return coins[i][j]
            a=(i,j,pw)
            if(dp[i][j][pw] is not None):
                return dp[i][j][pw]
            ans=coins[i][j]+max(rec(i+1,j,pw),rec(i,j+1,pw))
            if(coins[i][j]<0 and pw>0):
                ans=max(ans,max(rec(i+1,j,pw-1),rec(i,j+1,pw-1)))
            dp[i][j][pw]=ans
            return ans
        return rec(0,0,2)
```
