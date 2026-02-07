# 📅 Daily CP Solutions — 2026-02-07

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Max-Sum-In-The-Configuration
**Platform:** GeeksforGeeks

Problem Insight:
The problem seeks the maximum sum of (index * value) across all possible array rotations. A linear recurrence relation exists to efficiently compute the sum for each rotation based on the previous one.

Approach:
First, calculate the initial sum (sum(i * arr[i])) and the total sum of all elements. Then, iterate N-1 times, using a recurrence (F(k) = F(k-1) + total_sum - n * arr[n-k]) to calculate the sum for each subsequent rotation. Keep track of the maximum sum found.

Time Complexity:
O(N)
Initial calculation of sum and total takes O(N), and subsequent N-1 rotations are calculated in O(1) each using the recurrence.

Space Complexity:
O(1)
Only a few constant variables are used to store sums and results.

Optimization Notes:
This solution is optimal. It achieves O(N) time complexity because it requires at least one pass through the array to calculate initial sums. The O(1) space complexity is also optimal as no additional data structures proportional to input size are used.

### 💻 Implementation
```py
class Solution:
    def maxSum(self, arr):
        n = len(arr)
        arr_sum = sum(arr)

        curr = sum(i * val for i, val in enumerate(arr))
        res = curr

        for i in range(1, n):
            curr = curr + arr_sum - n * arr[n-i]
            res = max(res, curr)

        return res
```

## 🔹 Leetcode Minimum-Deletions-To-Make-String-Balanced
**Platform:** LeetCode

Problem Insight:
A balanced string consists of zero or more 'a's followed by zero or more 'b's. This implies there's a conceptual split point where characters to its left should ideally be 'a's and characters to its right should ideally be 'b's.

Approach:
The solution iterates through all possible split points in the string. For each split point, it calculates the count of 'b's appearing before or at the split point and the count of 'a's appearing after the split point. The sum of these two counts represents the minimum deletions required for that specific split, and the overall minimum is tracked.

Time Complexity:
O(N)
The initial s.count('a') takes O(N), and the loop iterates N times with O(1) work per iteration.

Space Complexity:
O(1)
Only a fixed number of variables are used, independent of the input string length.

Optimization Notes:
The solution is optimal. It processes each character in the string a constant number of times (initial count and one pass), achieving O(N) time complexity. It also uses constant extra space, which is the best possible.

### 💻 Implementation
```py
class Solution:
    def minimumDeletions(self, s: str) -> int:
        n=len(s)
        a,b=s.count('a'),0
        res=a
        for i in range(n):
            if(s[i]=='a'):a-=1
            else:b+=1
            res=min(res,a+b)
        return res
```
