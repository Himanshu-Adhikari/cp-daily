# 📅 Daily CP Solutions — 2026-03-07

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Dice Throw
**Platform:** GeeksforGeeks

Problem Insight:
This problem counts the number of ways to achieve a target sum using a specific number of dice with a given range of faces. It exhibits optimal substructure and overlapping subproblems, making it suitable for dynamic programming.

Approach:
The solution uses a 2D dynamic programming array a[i][k] where a[i][k] represents the number of ways to reach the final target sum x, given that i dice have already been rolled and their current sum is k. The table is filled iteratively by considering states from (n, x) backward to (0, 0), summing up possibilities for each die roll.

Time Complexity:
O(N * M * X)
There are N levels for the number of dice, X states for the current sum, and M choices for each die roll, resulting in N*M*X operations.

Space Complexity:
O(N * X)
A 2D array of size (N+1) x (X+1) is used to store all intermediate DP states.

Optimization Notes:
The time complexity of O(N * M * X) is generally optimal for this problem with standard DP. The space complexity can be optimized to O(X) by noticing that the current row's calculation only depends on the immediately next row's values, allowing the use of only two rows (current and next) instead of the full N rows.

### 💻 Implementation
```cpp
class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        int a[n+1][x+1];
        memset(a,0,sizeof(a));
        a[n][x]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=m;j++){
                for(int k=0;k<=x-j;k++){
                    a[i][k]+=a[i+1][k+j];
                }
            }
        }
        return a[0][0];
    }
};
```

## 🔹 Leetcode 1888 Minimum-Number-Of-Flips-To-Make-The-Binary-String-Alternating
**Platform:** LeetCode

Problem Insight:
Cyclic shifts of a string can be represented by a sliding window over the doubled string. There are only two possible alternating patterns ("0101..." or "1010...") to match.

Approach:
Construct a doubled string `s+s`. Use a sliding window of length `n` (original string length) to represent all cyclic shifts. Maintain two counts for flips needed to make the current window match "0101..." and "1010..." respectively, adjusting counts as the window slides. The minimum of these two counts for each window is a candidate for the overall minimum.

Time Complexity:
O(N)
The loop runs 2N times, with constant time operations inside, and string concatenation takes O(N).

Space Complexity:
O(N)
A new string `s+s` of length 2N is created.

Optimization Notes:
The solution is optimal in terms of time complexity. While O(N) space is used for `s+s`, it can be optimized to O(1) by calculating `s[i % n]` on the fly instead of explicitly constructing the doubled string. However, for typical constraints, the current approach is clean and efficient enough.

### 💻 Implementation
```py
class Solution:
    def minFlips(self, s: str) -> int:
        t=s+s
        n=len(s)
        a,b=0,0
        res=n
        for i in range(len(t)):
            if t[i]!=('0' if i%2==0 else '1'): a+=1
            if t[i]!=('1' if i%2==0 else '0'): b+=1
            
            if i>=n:
                if t[i-n]!=('0' if (i-n)%2==0 else '1'): a-=1
                if t[i-n]!=('1' if (i-n)%2==0 else '0'): b-=1
            
            if i>=n-1:
                res=min(res,a,b)
        return res
```
