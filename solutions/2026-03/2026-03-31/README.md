# 📅 Daily CP Solutions — 2026-03-31

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Buy-Stock-With-Transaction-Fee
**Platform:** GeeksforGeeks

Problem Insight:
This problem aims to find the maximum profit from buying and selling a stock multiple times, with a fixed transaction fee applied per purchase. It is a classic dynamic programming problem tracking current possession of a stock.

Approach:
The solution uses a bottom-up dynamic programming approach. It defines two states for each day: dp[i][1] represents the maximum profit achievable from day i onwards if currently holding a stock, and dp[i][0] represents the maximum profit if not holding a stock. The loop iterates from the last day backwards, calculating these states by considering options to buy, sell, or do nothing.

Time Complexity:
O(N) where N is the number of days (arr.size()).
The solution iterates through the array once in reverse, performing constant time operations in each step.

Space Complexity:
O(N) where N is the number of days.
A 2D DP table of size (N+1) x 2 is used to store the intermediate maximum profits for each day and state.

Optimization Notes:
The solution is optimal in terms of time complexity, as all prices must be considered. Space complexity can be optimized to O(1) by noticing that the current day's DP values only depend on the next day's values. Only two variables (for dp_hold and dp_cash from the previous day) are needed to calculate the current day's values.

CODE:
class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(2));
        for(int i=n-1; i>=0; i--){
            dp[i][1] = max(dp[i+1][0]-k-arr[i], dp[i+1][1]);
            dp[i][0] = max(dp[i+1][1]+arr[i], dp[i+1][0]);
        }
        return dp[0][1];
    }
};

### 💻 Implementation
```cpp
class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(2));
        for(int i=n-1; i>=0; i--){
            dp[i][1] = max(dp[i+1][0]-k-arr[i], dp[i+1][1]);
            dp[i][0] = max(dp[i+1][1]+arr[i], dp[i+1][0]);
        }
        return dp[0][1];
    }
};
```

## 🔹 Leetcode Lexicographically-Smallest-Generated-String
**Platform:** LeetCode

Problem Insight:
Reconstruct a target string of length len(s) + len(t) - 1 by applying 'T' (must match) and 'F' (must not match) constraints from a pattern string 's' with respect to a fixed substring 't'. Conflicts or unsolvable constraints yield an empty string.

Approach:
Initialize the result with wildcards. First, apply all 'T' constraints, filling characters from 't' into the result string, and return an empty string if conflicts arise. Then, process 'F' constraints: if a segment would match 't', modify one of its original wildcard positions to break the match, using 'a' and 'b' as default fill characters.

Time Complexity:
O(len(s) * len(t))
Each of the len(s) constraints in string 's' potentially requires iterating through len(t) characters of 't' for checks and assignments.

Space Complexity:
O(len(s) + len(t))
The space is dominated by storing the result string and its temporary copy, each of length len(s) + len(t) - 1.

Optimization Notes:
The solution is optimal. The problem's nature requires processing each of the len(s) potential pattern placements, each involving len(t) characters, which inherently leads to an O(len(s) * len(t)) time complexity lower bound. Space usage is minimal, storing only the necessary result string.

### 💻 Implementation
```py
class Solution:
    def generateString(self, s: str, t: str) -> str:
        n, m = len(s), len(t)
        ans = ['?'] * (n + m - 1)  
        for i, b in enumerate(s):
            if b != 'T':
                continue
            for j, c in enumerate(t):
                v = ans[i + j]
                if v != '?' and v != c:
                    return ""
                ans[i + j] = c
        
        old_ans = ans
        ans = ['a' if c == '?' else c for c in ans] 
        for i, b in enumerate(s):
            if b != 'F':
                continue
            if ''.join(ans[i: i + m]) != t:
                continue
            for j in range(i + m - 1, i - 1, -1):
                if old_ans[j] == '?':
                    ans[j] = 'b'
                    break
            else:
                return ""
        return ''.join(ans)
```
