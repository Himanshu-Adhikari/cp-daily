# 📅 Daily CP Solutions — 2026-05-03

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Sort By Set Bit Count
**Platform:** GeeksforGeeks

Problem Insight:
The goal is to sort an array of integers primarily by their set bit count in descending order. Numbers with more set bits should come before numbers with fewer.

Approach:
The solution uses Python's built-in sort method with a custom key. The key for each element is computed by negating its set bit count, effectively sorting in descending order of bit counts.

Time Complexity:
O(N log N * log M) where N is array length and M is max element value. Python's Timsort is O(N log N), and x.bit_count() takes O(log M) time.

Space Complexity:
O(N) where N is array length. Python's Timsort uses O(N) auxiliary space in the worst case.

Optimization Notes:
This solution is optimal for comparison-based sorting of general integers, achieving O(N log N) sorting time. The use of the built-in bit_count() is efficient.

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
A string 'goal' is a rotation of 's' if and only if 'goal' has the same length as 's' and 'goal' is a substring of 's' concatenated with itself. This trick leverages the cyclic nature of string rotations.

Approach:
The solution first verifies that the lengths of the original string 's' and the 'goal' string are equal. If they are, it concatenates 's' with itself (s + s) and then checks if 'goal' is present as a substring within this newly created doubled string.

Time Complexity:
O(N)
String concatenation s+s takes O(N) and Python's string substring check 'in' is highly optimized to run in O(N) time, where N is the length of the strings.

Space Complexity:
O(N)
A new string s+s of length 2N is created, requiring O(N) auxiliary space.

Optimization Notes:
This solution is optimal in terms of time complexity, as it is impossible to solve the problem in less than O(N) time (all characters must be examined). The O(N) space complexity is inherent to the chosen approach due to string immutability in Python and the creation of the doubled string.

### 💻 Implementation
```py
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        s=s+s
        return True if len(s)==len(goal)*2 and goal in s else False
```
