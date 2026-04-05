# 📅 Daily CP Solutions — 2026-04-05

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Target Sum
**Platform:** GeeksforGeeks

Problem Insight:
This problem aims to find the total number of ways to assign plus or minus signs to each element in an array such that the sum of the signed elements equals a given target.

Approach:
The solution uses a recursive approach with memoization (dynamic programming). It explores two options for each element: adding the element to the current sum or subtracting it. The DP state is defined by (current index, current accumulated sum) to store and retrieve previously computed results.

Time Complexity:
O(N * S)
N is the length of the array, and S (2001 in the code) is the maximum possible range of the sum values. Each state is computed in O(1) time.

Space Complexity:
O(N * S)
This is for the DP table of size (N+1) x 2001. Additional space for the recursion stack is O(N).

Optimization Notes:
The dynamic programming approach is optimal for this problem. However, the current implementation has a critical flaw as it uses 'sm' directly as an array index, which will fail if 'sm' can be negative. To correctly handle the full range of possible sums (including negative values), a sum offset should be applied to map 'sm' to a non-negative index in the DP table.

### 💻 Implementation
```py
class Solution:
    def totalWays(self, arr, target):
        n=len(arr)
        dp=[[-1 for i in range(2001)] for j in range(n+1)]
        def rec(i,sm):
            if(i==n):return sm==target
            if(dp[i][sm]!=-1):return dp[i][sm]
            res= rec(i+1,sm+arr[i])+rec(i+1,sm-arr[i])
            dp[i][sm]=res
            return res
        return rec(0,0);
```

## 🔹 Leetcode Robot Return To Origin
**Platform:** LeetCode

Problem Insight:
To return to the starting point, the total displacement in both the horizontal and vertical directions must be zero.

Approach:
Initialize two counters, one for vertical displacement and one for horizontal displacement, to zero. Iterate through the input string, incrementing or decrementing the appropriate counter for each move. Finally, return true if both counters are zero, indicating no net displacement.

Time Complexity:
O(N) where N is the length of the moves string. The solution iterates through the string once to process all moves.

Space Complexity:
O(1). Only a constant number of variables (two counters) are used regardless of the input string's length.

Optimization Notes:
This solution is optimal. It processes each move exactly once and uses a constant amount of extra space, which are the best possible complexities for this problem.

### 💻 Implementation
```py
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        x,y=0,0
        for i in moves:
            if(i=='U'):x-=1
            elif(i=='R'):y+=1
            elif(i=='D'):x+=1
            else:y-=1
        return not x and not y
```
