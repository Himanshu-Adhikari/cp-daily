# 📅 Daily CP Solutions — 2026-05-04

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Palindrome Binary
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires checking if the sequence of bits in the binary representation of an integer forms a palindrome.

Approach:
The solution converts the integer into its binary string form, removes the "0b" prefix, and then compares this binary string with its reversed version. If they are identical, the number's binary representation is a palindrome.

Time Complexity:
O(log n)
Converting to a binary string, slicing, reversing, and comparing strings all take time proportional to the number of bits in n (log n).

Space Complexity:
O(log n)
Storing the binary string and its reversed copy requires space proportional to the number of bits in n (log n).

Optimization Notes:
The time complexity is optimal as all bits must be examined. However, space complexity can be optimized to O(1) by using a bit manipulation approach that compares bits from both ends of the number without explicit string conversion.

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
A 90-degree clockwise rotation of a square matrix can be achieved by first transposing the matrix, then reversing each of its rows.

Approach:
The solution first transposes the matrix in-place by swapping elements across the main diagonal. Then, it iterates through each row and reverses the elements within that row to complete the rotation.

Time Complexity:
O(N^2)
Both the transpose operation and the row reversal operation iterate through all N*N elements of the matrix once.

Space Complexity:
O(1)
The operations are performed in-place. Although Python slicing creates a temporary list for each row reversal, no persistent additional data structures are used that scale with N.

Optimization Notes:
It is optimal. The time complexity of O(N^2) is the lower bound because every element in the N*N matrix must be read and written to achieve the rotation. The space complexity is also optimal as the rotation is performed in-place.

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
