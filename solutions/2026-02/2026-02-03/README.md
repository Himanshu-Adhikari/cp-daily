# 📅 Daily CP Solutions — 2026-02-03

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Buy-Stock-2
**Platform:** GeeksforGeeks

Problem Insight:
The key to maximizing profit is to buy low and sell high. For any given buying day, the optimal selling day must be one in the future with the highest possible price.

Approach:
The solution iterates backward through the prices, keeping track of the maximum price encountered from the current day to the end of the array. For each day, it calculates the potential profit by subtracting the current day's price from this maximum future price and updates the overall maximum profit.

Time Complexity:
O(n)
The single loop iterates through the prices array once from right to left.

Space Complexity:
O(1)
Only a few constant extra variables are used for storing the result and maximum price.

Optimization Notes:
This solution is optimal. It achieves O(n) time complexity and O(1) space complexity, which is the most efficient possible as every price must be examined at least once.

### 💻 Implementation
```py
class Solution:
    def maxProfit(self, prices):
        res,n=0,len(prices)
        pr=prices[-1]
        for i in range(n-2,-1,-1):
            res=max(res,pr-prices[i])
            pr=max(pr,prices[i])
        return res
```

## 🔹 Leetcode 3637 Trionic-Array-I
**Platform:** LeetCode

Problem Insight:
The array must conform to a specific "trionic" shape: strictly increasing, followed by strictly decreasing, followed by another strictly decreasing segment. All three parts must contain at least two elements.

Approach:
First, identify the longest strictly increasing prefix ending at index 'l'. Next, find the longest strictly decreasing suffix starting at index 'j'. Then, verify structural constraints: the increasing prefix must have at least two elements, the decreasing suffix must have at least two elements, and 'l' must be strictly less than 'j'. Finally, ensure the segment from 'nums[l]' to 'nums[j]' is also strictly decreasing.

Time Complexity:
O(N) because the solution involves three separate loops, each iterating through the array at most once.

Space Complexity:
O(1) because the solution only uses a few constant-space variables for indices and temporary comparisons.

Optimization Notes:
The solution is optimal in both time and space complexity. It requires examining all elements at least once (O(N) time) and uses constant extra space (O(1) space). No further significant optimization is possible.

### 💻 Implementation
```py
class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        l,n=0,len(nums)
        pr=nums[0]-1
        for i in range(n):
            if(nums[i]<=pr):
                break
            pr=nums[i]
            l=i
        pr=nums[-1]+1
        j=n-1
        for i in range(n-1,-1,-1):
            if(nums[i]>=pr):
                break
            pr=nums[i]
            j=i
        pr=nums[l]+1
        if(l==0 or j==n-1 or l>=j):return False
        for i in range(l,j+1):
            if(pr<=nums[i]):return False
            pr=nums[i]
        return True
```
