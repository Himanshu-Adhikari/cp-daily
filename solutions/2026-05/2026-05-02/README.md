# 📅 Daily CP Solutions — 2026-05-02

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Position Of The Set Bit
**Platform:** GeeksforGeeks

Problem Insight:
The problem aims to identify if a given positive integer is a power of two. If it is, the solution should return the 1-based position of its single set bit; otherwise, it should return -1.

Approach:
The solution first handles the base case for n=1. It then uses the property that for a power of two, n equals 2 to the power of log2(n). It checks this equality after truncating log2(n) to an integer. If equal, it returns the 1-based log2(n) as the position.

Time Complexity:
O(1)
Mathematical functions like log2 and bit shifts are considered constant time operations.

Space Complexity:
O(1)
The solution uses a fixed amount of memory for variables, independent of the input size.

Optimization Notes:
The solution is not optimal in terms of robustness and efficiency for all integer inputs. It does not handle n <= 0, where log2(n) is undefined or leads to errors. A more robust check for a positive power of two uses bitwise operations (n > 0 && (n & (n - 1)) == 0). Floating-point math (log2) can also introduce precision issues for very large integers, and bitwise operations are generally faster and more reliable for bit manipulation tasks.

### 💻 Implementation
```cpp
class Solution {
  public:
    int findPosition(int n) {
        if(n==1)return 1;
        if((1<<int(log2(n)))!=n)return -1;
        return log2(n)+1;
    }
};
```

## 🔹 Leetcode Rotated Digits
**Platform:** LeetCode

Problem Insight:
A number is "good" if its rotated version is valid and different from the original. Digits 3, 4, 7 are invalid for rotation.

Approach:
The solution iterates through each number from 1 to N. For each number, it converts it to a string and checks if all digits are valid for rotation. If so, it constructs the rotated number and verifies if it is different from the original.

Time Complexity:
O(N log N)
The outer loop runs N times. Inside, string conversion and digit processing take O(log N) time for a number with log N digits.

Space Complexity:
O(log N)
The dictionary uses constant space. Converting numbers to strings requires O(log N) space for numbers up to N.

Optimization Notes:
This approach is optimal for the given constraints (typically N <= 10^4) as N log N is efficient enough. For much larger N (e.g., 10^9), a dynamic programming approach (digit DP) would be necessary to achieve an optimal O(log N) time complexity.

### 💻 Implementation
```py
class Solution:
    def rotatedDigits(self, n: int) -> int:
        res=0
        d={"1":"1","2":"5","5":"2","6":"9" ,"9":"6","0":"0","8":"8"}
        def rec(n:int)->bool:
            s=str(n)
            vl=0
            for i in s:
                if(i not in d):return False
                vl=vl*10+int(d[i])
            return vl!=n
        for i in range(1,n+1):
            if(rec(i)):
                res+=1
        return res
```
