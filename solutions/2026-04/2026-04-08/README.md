# 📅 Daily CP Solutions — 2026-04-08

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Segregate 0S And 1S
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires arranging an array containing only 0s and 1s such that all 0s precede all 1s. This is a common segregation task.

Approach:
The solution sorts the entire array. Since 0 is less than 1, a standard sort will naturally place all 0s at the beginning of the array, followed by all 1s.

Time Complexity:
O(N log N)
Python's list.sort() uses Timsort, which has an average and worst-case time complexity of O(N log N) where N is the number of elements.

Space Complexity:
O(N)
Python's Timsort implementation can use up to O(N) auxiliary space in the worst-case for temporary arrays during its merge operations.

Optimization Notes:
This solution is not optimal. For an array containing only 0s and 1s, the problem can be solved in O(N) time using a two-pointer approach or by counting the occurrences of 0s and 1s, both requiring O(1) auxiliary space.

### 💻 Implementation
```py
class Solution:
    def segregate0and1(self, arr):
        arr.sort()
            
                
```

## 🔹 Leetcode Xor-After-Range-Multiplication-Queries-I
**Platform:** LeetCode

Problem Insight:
The task involves applying multiple strided range updates (multiplication modulo a prime) to an array, and then calculating the XOR sum of all final array elements. The stride parameter 'k' varies per query.

Approach:
The solution directly simulates each query by iterating through the specified range [l, r] with step 'k' and applying the modulo multiplication. After all updates, it performs a single linear scan through the modified array to compute the final XOR sum.

Time Complexity:
O(Q * N)
Each query can iterate through up to N elements (when k=1), and there are Q queries, plus an O(N) pass for the XOR sum.

Space Complexity:
O(1)
The solution modifies the input array in-place and uses only a constant amount of auxiliary space.

Optimization Notes:
The solution is not optimal. The O(Q*N) complexity is too slow for typical competitive programming constraints where N and Q can be up to 10^5. This type of strided range update problem can often be optimized using techniques like square root decomposition, achieving complexities closer to O(Q * sqrt(N)).

### 💻 Implementation
```py
class Solution:
    MOD = 10**9 + 7

    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        for l, r, k, v in queries:
            for i in range(l, r + 1, k):
                nums[i] = (nums[i] * v) % self.MOD

        res = 0
        for x in nums:
            res ^= x

        return res
```
