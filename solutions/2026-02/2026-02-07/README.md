# 📅 Daily CP Solutions — 2026-02-07

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Max-Sum-In-The-Configuration
**Platform:** GeeksforGeeks

Problem Insight:
This problem requires finding the maximum possible sum of (index * value) by rotating a given array. The key insight is that the sum for one rotation can be efficiently derived from the sum of the previous rotation.

Approach:
First, calculate the sum for the original, unrotated array. Then, use a dynamic programming approach where the sum for the k-th rotation (F(k)) is computed from the sum of the (k-1)-th rotation (F(k-1)). The recurrence F(k) = F(k-1) + arr_sum - n * arr[n-k] is used for right rotations, efficiently updating the sum by accounting for the element moving from the end to the front. The maximum sum encountered across all rotations is tracked and returned.

Time Complexity:
O(N)
Calculating the initial sum takes O(N), and the loop iterates N-1 times, with each iteration performing constant time operations.

Space Complexity:
O(1)
The solution uses only a few auxiliary variables to store sums and array length, which is constant space regardless of input size.

Optimization Notes:
This solution is optimal. It achieves linear time complexity, O(N), because it visits each element a constant number of times (once for the initial sum and then each rotation update takes constant time). Since all elements must be considered, no asymptotically faster approach exists.

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
A balanced string consists of zero or more 'a's followed by zero or more 'b's. This implies there is a "split point" where all characters to its left are 'a's and all characters to its right are 'b's, requiring deletions of 'b's on the left and 'a's on the right.

Approach:
The solution iterates through all n+1 possible split points in the string (including before the first character and after the last). For each potential split point, it calculates the number of 'b's that must be deleted from the prefix and the number of 'a's that must be deleted from the suffix to achieve a balanced string, then tracks the minimum total deletions.

Time Complexity:
O(N) where N is the length of the string. It involves an initial pass to count 'a's (O(N)) and a single loop through the string (O(N)), with constant time operations inside the loop.

Space Complexity:
O(1). Only a few integer variables are used to store counts, independent of the input string's length.

Optimization Notes:
The solution is optimal. It solves the problem in a single pass (after an initial character count), which is the most efficient approach as it directly computes and minimizes the deletions for all possible split configurations.

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
