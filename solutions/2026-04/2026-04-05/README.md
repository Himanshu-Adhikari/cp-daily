# 📅 Daily CP Solutions — 2026-04-05

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Target Sum
**Platform:** GeeksforGeeks

Problem Insight:
This solution addresses the classic "Target Sum" problem, aiming to count the number of ways to assign plus or minus signs to array elements such that their sum equals a specific target value.

Approach:
It uses a top-down dynamic programming approach with memoization. The recursive function explores all possible combinations by either adding or subtracting each element, and stores the results for (index, current sum) states to avoid redundant computations.

Time Complexity:
O(N * S_max)
Where N is the length of the array and S_max is the maximum possible range of sums (implicitly 2001 in the code, representing the maximum shifted sum). Each state is computed once in O(1).

Space Complexity:
O(N * S_max)
This is due to the memoization table (dp array) which stores results for N array indices and S_max possible sum values, plus O(N) for the recursion stack depth.

Optimization Notes:
The solution is optimal in terms of its pseudo-polynomial time complexity for this problem. However, the current code implicitly assumes 'sm' (the sum) will always be non-negative and within [0, 2000] when used as an index. For a general "Target Sum" problem where intermediate sums can be negative, 'sm' needs to be explicitly shifted by an offset (e.g., sum(abs(arr))) to map to valid non-negative indices. The space complexity could be optimized to O(S_max) using an iterative bottom-up DP approach that only stores the results for the current and previous rows.

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
The problem asks to determine if a robot, starting at the origin, returns to the origin after performing a sequence of directional moves. This means the net displacement along both axes must be zero.

Approach:
Initialize two variables, representing the robot's x and y coordinates, to zero. Iterate through the input string of moves. For each 'U' or 'D' move, adjust the y-coordinate, and for each 'L' or 'R' move, adjust the x-coordinate. Finally, return true if both x and y coordinates are zero, indicating the robot has returned to the start.

Time Complexity:
O(N) where N is the length of the moves string.
The algorithm iterates through the input string exactly once.

Space Complexity:
O(1).
Only a constant number of variables are used to track the coordinates and loop, independent of input size.

Optimization Notes:
This solution is optimal. It requires processing each move at least once, leading to an unavoidable O(N) time complexity. It also uses minimal O(1) extra space, making it efficient in both time and space. No further significant algorithmic optimization is possible.

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
