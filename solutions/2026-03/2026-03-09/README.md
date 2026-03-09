# 📅 Daily CP Solutions — 2026-03-09

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Largest Number With One Swap
**Platform:** GeeksforGeeks

Problem Insight:
The goal is to find the lexicographically largest string by performing at most one swap of two characters. This involves identifying the first position that can be improved and finding the best character to move there.

Approach:
The solution first creates a sorted-descending version of the input string to identify the ideal character order. It then finds the first index from the left where the original string differs from this ideal order. If such a position is found, it locates the rightmost occurrence of the ideal character in the original string and performs a swap.

Time Complexity:
O(N log N)
Sorting the list of characters dominates the time complexity.

Space Complexity:
O(N)
Two auxiliary lists (t and p) are created, each storing N characters, plus the result string.

Optimization Notes:
The solution is not optimal in terms of time complexity. An O(N) solution is possible by avoiding the initial O(N log N) sort. This can be achieved by pre-computing the last occurrence index for each digit ('0'-'9'). Then, iterate through the string, and for each position, check if a larger digit exists at a later index using the pre-computed last occurrences. This reduces time to O(N) while maintaining O(N) space.

### 💻 Implementation
```py
class Solution:
    def largestSwap(self, s):
        t=[i for i in s]
        t.sort(reverse=True)
        p=[i for i in s]
        i,n=0,len(s)
        while(i<n):
            if(s[i]==t[i]):
                i+=1
            else:
                break
        if(i==n):return s
        j=n-1
        while(j>=0 and s[j]!=t[i]):
            j-=1
        p[j],p[i]=p[i],p[j]
        res=""
        for i in p:
            res+=i
        return res
```

## 🔹 Leetcode 3129 Find All Possible Stable Binary Arrays I
**Platform:** LeetCode

Problem Insight:
This problem asks us to count the number of stable arrays with specific counts of zeros and ones, where "stable" means no more than a given limit of consecutive identical characters.

Approach:
A 3D dynamic programming approach is used. dp[i][j][k] represents the number of stable arrays with 'i' zeros, 'j' ones, ending with character 'k' (0 for zero, 1 for one). Transitions are calculated by summing valid previous states and subtracting invalid ones that would exceed the consecutive character limit, effectively using a sliding window sum technique.

Time Complexity:
O(zero * one)
The solution uses nested loops iterating up to 'zero' and 'one' respectively, with constant time operations inside the loops.

Space Complexity:
O(zero * one)
A 3D DP array of size (zero + 1) * (one + 1) * 2 is allocated to store all intermediate states.

Optimization Notes:
The time complexity is optimal for this type of problem where all subproblems involving 'zero' and 'one' counts need to be considered. Space complexity could be optimized to O(min(zero, limit) * one) or O(zero * min(one, limit)) using a rolling array approach, depending on iteration order and which dimension 'limit' affects most significantly, but the current O(zero * one) is generally acceptable given typical constraints.

### 💻 Implementation
```cpp
class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int dp[zero + 1][one + 1][2];
        memset(dp, 0, sizeof(dp));
        for (int i = min(zero, limit); i >= 0; i--)
            dp[i][0][0] = 1;
        for (int j = min(one, limit); j >= 0; j--)
            dp[0][j][1] = 1;
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                // append 0
                dp[i][j][0] = (0LL + dp[i - 1][j][0] + dp[i - 1][j][1]
                                - (i - 1 - limit >= 0 ? dp[i - 1 - limit][j][1] : 0)
                                + MOD) % MOD;

                // append 1
                dp[i][j][1] = (0LL + dp[i][j - 1][0] + dp[i][j - 1][1]
                                - (j - 1 - limit >= 0 ? dp[i][j - 1 - limit][0] : 0)
                                + MOD) % MOD;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
```
