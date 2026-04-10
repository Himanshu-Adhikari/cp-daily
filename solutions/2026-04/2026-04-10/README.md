# 📅 Daily CP Solutions — 2026-04-10

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Sorted Subsequence Of Size 3
**Platform:** GeeksforGeeks

Problem Insight:
The problem aims to find three elements in an array, a < b < c, in linear time and constant space. This can be achieved by keeping track of the smallest first and second elements found so far.

Approach:
Iterate through the array, maintaining three values: the smallest element encountered overall (fe), the smallest first element of a valid pair (f), and the smallest second element of a valid pair (s). Update fe if a smaller number is found. If the current number can form a better (f, s) pair with fe, update f and s. If the current number is greater than s, a triplet (f, s, current_number) is found.

Time Complexity:
O(N)
The solution iterates through the array once, performing constant time operations in each step.

Space Complexity:
O(1)
A constant number of variables (f, s, fe) are used, independent of the input array size.

Optimization Notes:
This solution is optimal. It achieves the problem's goal in a single pass through the array (linear time) and uses only a fixed amount of auxiliary memory (constant space). No further significant asymptotic improvements can be made.

### 💻 Implementation
```py
class Solution:
    def find3Numbers(self, arr):
        f,s=float('inf'),float('inf')
        fe=float('inf')
        for i in arr:
            if(i<=fe):fe=i
            elif(i<=s):
                f=fe
                s=i
            else:
                return [f,s,i]
        return []
```

## 🔹 Leetcode Minimum-Distance-Between-Three-Equal-Elements-I
**Platform:** LeetCode

Problem Insight:
The problem seeks the minimum value of 2 * (latest_index - third_latest_index) for any number that appears at least three times in the input array. If no such number exists, -1 is returned.

Approach:
Iterate through the array, storing all indices for each unique number in a hash map. For every number encountered, if its count exceeds two, calculate the distance between its current (latest) index and its third-to-last recorded index, then update the minimum found.

Time Complexity:
O(N)
The algorithm iterates through the input array once, performing constant-time hash map operations for each element on average.

Space Complexity:
O(N)
In the worst case, the hash map stores all N indices across its lists, for example, if all numbers are unique or all are the same.

Optimization Notes:
The solution is optimal. It processes each element once and uses a hash map for efficient lookups and storage of indices, which is necessary to track multiple occurrences of numbers.

### 💻 Implementation
```py
class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        aux=defaultdict(list)
        res=-1
        for i,val in enumerate(nums):
            # if(val not in aux):aux[val]=[]
            aux[val].append(i)
            if(len(aux[val])>2):
                calc=2*(aux[val][-1] - aux[val][-3])
                if(res==-1):
                    res=calc
                else:res=min(res,calc)
        return res
```
