# 📅 Daily CP Solutions — 2026-01-25

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Valid-Number-Of-Parenthesis
**Platform:** GeeksforGeeks

Problem Insight:
This problem asks to find the number of valid sequences of balanced parentheses of a given length N. A sequence is valid if it has N/2 opening and N/2 closing brackets, and prefix counts of opening brackets are always >= closing brackets.

Approach:
The solution uses a recursive depth-first search approach. It maintains counts of remaining open and close brackets. It explores adding an opening or closing bracket based on whether it maintains validity (e.g., cannot add a closing bracket if it would make prefix unbalanced) and if brackets are available.

Time Complexity:
O(4^(N/2)). The recursive solution without memoization recomputes many subproblems, leading to exponential time complexity.

Space Complexity:
O(N). This is due to the maximum depth of the recursion stack, which can go up to N levels.

Optimization Notes:
The current solution is not optimal. It can be significantly improved by adding memoization to store results of (o, c) states, reducing time complexity to O(N^2) and space to O(N^2). This problem counts Catalan numbers, which can be computed in O(N) time and O(1) space using a direct mathematical formula or iterative DP.

### 💻 Implementation
```py
class Solution:
    def findWays(self, n):
        if(n%2==1):
            return 0
        def rec(o,c):
            if(not o and not c):return 1
            cs=0
            if(o==c):
                an=rec(o-1,c)
                cs+=an
            else:
                if(c>o):
                    an=rec(o,c-1)
                    cs+=an
                if(o):
                    an=rec(o-1,c)
                    cs+=an
            return cs
        res=rec(n//2,n//2)
        return res    
```

## 🔹 Leetcode 1984 Minimum-Difference-Between-Highest-And-Lowest-Of-K-Scores
**Platform:** LeetCode

Problem Insight:
To minimize the difference between the largest and smallest of any k chosen numbers, those k numbers must be contiguous in the sorted version of the entire array.

Approach:
Sort the input array. Then, use a sliding window of size k to iterate through all possible contiguous subarrays. For each window, calculate the difference between its last and first elements and find the minimum of these differences.

Time Complexity:
O(N log N)
Dominated by the sorting step of the array, the subsequent loop is O(N).

Space Complexity:
O(1)
The sorting is done in-place, and only a few variables are used for iteration and result storage.

Optimization Notes:
The solution is optimal. Sorting takes O(N log N) time, which is the lower bound for comparison-based selection problems involving ranges. Once sorted, finding the minimum difference becomes an O(N) scan. No significant improvements can be made without changing the sorting algorithm paradigm (e.g., using non-comparison sorts if data range allows, which is rarely the case for general integer problems).

### 💻 Implementation
```py
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        n=len(nums)
        return min(nums[i+k-1]-nums[i] for i in range(n-k+1))
```
