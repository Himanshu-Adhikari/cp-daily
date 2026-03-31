# 📅 Daily CP Solutions — 2026-03-31

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Buy-Stock-With-Transaction-Fee
**Platform:** GeeksforGeeks

Problem Insight:
This problem aims to find the maximum profit achievable from buying and selling stocks an unlimited number of times, with a fixed transaction fee 'k' applied to each buy operation. It is a dynamic programming problem tracking states of holding or not holding a stock.

Approach:
The solution uses dynamic programming with a bottom-up approach, iterating from the last day backwards. It calculates the maximum profit from day 'i' onwards for two states: holding a stock (dp[i][0]) and not holding a stock (dp[i][1]). The transaction fee 'k' is deducted when a stock is effectively bought.

Time Complexity:
O(N)
The solution iterates through the array of prices once, performing constant time operations for each day.

Space Complexity:
O(N)
A 2D DP table of size (N+1)x2 is used to store intermediate results, where N is the number of days.

Optimization Notes:
The current space complexity is O(N). This can be optimized to O(1) because the current day's DP values only depend on the next day's values. We only need to store two variables for the 'holding' and 'not holding' states from the previous iteration.

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
This problem aims to reconstruct a string of length N+M-1 based on a pattern S and a target string T, where S indicates required (T) or forbidden (F) occurrences of T as a substring.

Approach:
The solution first processes 'T' constraints to fix characters in the result string and detect immediate conflicts. Then, it addresses 'F' constraints by ensuring no forbidden substring matches T; if a match occurs, it modifies a placeholder character to break the match.

Time Complexity: O(N * M)
Justification: Both the 'T' and 'F' constraint processing involve nested loops that iterate up to N times for the outer loop and M times for the inner loop.

Space Complexity: O(N + M)
Justification: Two character arrays, 'ans' and 'old_ans', are used, each storing up to N + M - 1 characters.

Optimization Notes:
The solution is largely optimal for this problem type. The O(N*M) complexity is inherent in needing to check every possible alignment of T within the result string for both 'T' and 'F' constraints. Further optimization using advanced string algorithms is complex due to the mutable nature of the '?' characters for 'F' constraints.

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
