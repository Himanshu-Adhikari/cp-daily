# 📅 Daily CP Solutions — 2026-05-03

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Sort By Set Bit Count
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires sorting an array of integers based on their set bit count in descending order. The relative order of numbers with equal set bit counts is preserved by stable sorts.

Approach:
The solution leverages Python's built-in list.sort method. It uses a custom key function that computes the negative of the set bit count for each number, effectively achieving a descending sort based on bit counts.

Time Complexity:
O(N log N)
Sorting N elements using a comparison sort takes O(N log N) time, and bit_count() is O(1) for fixed-width integers.

Space Complexity:
O(N)
Python's Timsort (used by list.sort) requires O(N) auxiliary space in the worst case.

Optimization Notes:
This solution is optimal for comparison-based sorts, as O(N log N) is the theoretical lower bound. The bit_count() operation is highly optimized, often using hardware instructions. While non-comparison sorts like counting sort could theoretically sort by bit counts in O(N*k) time (where k is max bits), this approach is practical, concise, and typically performs very well.

### 💻 Implementation
```py
class Solution:
    def sortBySetBitCount(self, arr):
        arr.sort(key=lambda x:(-
        x.bit_count()))
        return arr
```

## 🔹 Leetcode Rotate String
**Platform:** LeetCode

Problem Insight:
A string s can be rotated to form goal if goal is a substring of s concatenated with itself, provided both strings have the same length.

Approach:
The solution first ensures that the original strings s and goal have identical lengths. Then, it concatenates s with itself and checks if goal exists as a substring within this doubled string.

Time Complexity:
O(N)
String concatenation takes O(N), and substring search (e.g., KMP-like algorithm) takes O(N) on a string of length 2N with pattern of length N, where N is the length of original s.

Space Complexity:
O(N)
Creating the doubled string s+s requires O(N) additional space, where N is the length of the original string s.

Optimization Notes:
This solution is optimal in terms of time complexity as it requires reading both strings, and space complexity is also optimal for approaches that construct the doubled string.

### 💻 Implementation
```py
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        s=s+s
        return True if len(s)==len(goal)*2 and goal in s else False
```
