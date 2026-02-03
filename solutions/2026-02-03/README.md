# 📅 Daily CP Solutions — 2026-02-03

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Buy-Stock-2
**Platform:** GeeksforGeeks

Problem Insight:
To maximize profit, we need to find the largest difference between a future selling price and a past buying price. This implies finding a peak after a valley.

Approach:
The solution iterates backwards from the second-to-last day. It maintains the maximum price encountered from the right (potential selling price) and updates the maximum profit by considering buying on the current day and selling at the highest price seen to its right.

Time Complexity:
O(N)
The solution iterates through the prices array once from right to left.

Space Complexity:
O(1)
It uses a fixed number of variables regardless of the input size.

Optimization Notes:
This solution is optimal. It processes each price exactly once to find the maximum profit, achieving the best possible time complexity of O(N).

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
This solution aims to identify if a given sequence of numbers is "trionic," meaning it strictly increases to a peak, then strictly decreases. It also applies specific constraints on the minimum length of the increasing and decreasing segments.

Approach:
The solution uses two passes to find key indices: 'l' for the peak from the left (end of increasing prefix) and 'j' for the start of the strictly decreasing suffix from the right. It then applies conditions for a valid trionic structure (e.g., ensuring both increasing and decreasing segments exist and have minimum length) before finally verifying the segment between 'l' and 'j' is strictly decreasing.

Time Complexity:
O(N)
Justification: The solution involves three separate loops, each iterating through the array at most once, resulting in a linear scan.

Space Complexity:
O(1)
Justification: Only a few integer variables are used to store indices and previous values, regardless of input size.

Optimization Notes:
The solution is optimal in terms of time complexity (O(N) is required to inspect all elements) and space complexity (O(1)). However, the specific definition of "trionic" implemented, particularly the condition j==n-1, seems to exclude sequences generally considered bitonic (like [1,2,3,2,1]) if the problem expects a standard definition. If a standard bitonic check is intended, this condition would need adjustment.

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
