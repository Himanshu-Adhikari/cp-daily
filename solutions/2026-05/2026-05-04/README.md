# 📅 Daily CP Solutions — 2026-05-04

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Palindrome Binary
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires checking if an integer's binary representation forms a palindrome.
This involves examining the sequence of bits from both ends.

Approach:
The solution converts the integer into its binary string representation, discarding the "0b" prefix. It then reverses this binary string.
Finally, it compares the original and reversed binary strings to determine if they are identical.

Time Complexity:
O(log N). Converting the integer to a binary string and performing string operations (reversal, comparison) are proportional to the number of bits (log N).

Space Complexity:
O(log N). Storing the binary string and its reversed copy consumes space proportional to the number of bits (log N).

Optimization Notes:
The solution is optimal in terms of Big-O complexity for a string-based approach. A bit manipulation method could achieve O(log N) time with O(1) space by comparing bits directly without explicit string allocation.

### 💻 Implementation
```py
class Solution:
    def isBinaryPalindrome(self, n):
        s=bin(n)[2:]
        r=s[::-1]
        return s==r
        
```

## 🔹 Leetcode Rotate Image
**Platform:** LeetCode

Problem Insight:
The problem requires rotating a square matrix 90 degrees clockwise in-place. A common strategy involves transposing the matrix and then reversing each row.

Approach:
The solution first transposes the matrix by swapping elements (i, j) with (j, i) only for the upper triangle. Afterwards, it reverses each row of the now transposed matrix, completing the 90-degree clockwise rotation.

Time Complexity:
O(N^2)
Both the transposition and the row reversal steps iterate through approximately N^2 elements of the N x N matrix.

Space Complexity:
O(N)
Using Python's matrix[i] = matrix[i][::-1] creates a temporary list of size N for each row during reversal.

Optimization Notes:
The solution is optimal in time complexity because every element of the N x N matrix must be visited. Space complexity can be improved to O(1) auxiliary space by reversing each row in-place using two pointers instead of creating new lists with slicing.

### 💻 Implementation
```py
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n,m=len(matrix),len(matrix[0])
        for i in range(0,n):
            for j in range(0,i+1):
                matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
        for i in range(n):
            matrix[i]=matrix[i][::-1]
        
```
