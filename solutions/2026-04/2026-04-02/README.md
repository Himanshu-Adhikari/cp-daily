# 📅 Daily CP Solutions — 2026-04-02

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Painting-The-Fence
**Platform:** GeeksforGeeks

Problem Insight:
This problem is a classic dynamic programming task that asks for the number of ways to paint n fences with k colors such that no more than two adjacent fences have the same color. It's often referred to as the Paint Fence problem.

Approach:
The solution uses dynamic programming by tracking two states for the current fence: the number of ways it has the same color as the previous fence, and the number of ways it has a different color. It iteratively calculates these counts for each fence from 2 to n, using modulo arithmetic to prevent overflow.

Time Complexity:
O(N)
The solution iterates through the fences from 3 to N once, performing constant time operations in each step.

Space Complexity:
O(1)
It uses a fixed number of variables to store the counts for the previous step, independent of N or K.

Optimization Notes:
The solution is optimal. It achieves O(N) time complexity, which is generally required as each fence needs to be considered, and O(1) space complexity, which is the best possible by only storing the necessary previous states.

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
This problem asks to find the maximum sum path from (0,0) to (n-1,m-1) in a grid, moving only down or right. We have a limited number of 'powers' (initially 2) that can be used to negate the value of a negative coin encountered.

Approach:
The solution uses 3-dimensional dynamic programming with memoization. The state is defined by (current row, current column, remaining powers). For each state, the function calculates the maximum value by considering moving down or right. If the current coin is negative and powers are available, it also considers using a power to skip the negative coin's penalty, which reduces the available powers.

Time Complexity:
O(N * M * K) where N is rows, M is columns, and K is max powers (3 in this case). Each state (i, j, pw) is computed once, and each computation takes constant time.

Space Complexity:
O(N * M * K) for storing the DP table. The table stores results for all possible (row, col, power) states.

Optimization Notes:
The solution is optimal in terms of asymptotic time and space complexity for this problem. It explores all necessary states to find the maximum path sum. Converting the top-down (memoized recursion) approach to a bottom-up (iterative) DP might offer minor constant factor performance improvements by avoiding recursion overhead, but would not change the Big-O complexity.

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
