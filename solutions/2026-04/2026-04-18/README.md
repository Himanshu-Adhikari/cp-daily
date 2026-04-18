# 📅 Daily CP Solutions — 2026-04-18

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Flip Bits
**Platform:** GeeksforGeeks

Problem Insight:
The goal is to maximize the count of ones by flipping at most one contiguous subsegment (0s become 1s, 1s become 0s). This boils down to finding a subsegment that maximizes (number of zeros in segment - number of ones in segment) and adding this to the total initial ones.

Approach:
A variation of Kadane's algorithm is used. The variable 'zero' tracks the current sum of (count of 0s - count of 1s) for the current subarray, treating 0 as +1 and 1 as -1. 'maxiContiZero' stores the maximum such sum found. The total initial ones are counted separately and added to this maximum difference.

Time Complexity:
O(N)
The algorithm iterates through the input array exactly once.

Space Complexity:
O(1)
It uses a fixed number of variables independent of the input array size.

Optimization Notes:
The solution is optimal. It processes each element once to find the maximum possible gain from a flip and the initial count of ones, achieving linear time complexity which is the most efficient possible.

### 💻 Implementation
```cpp
class Solution {
  public:
    int maxOnes(vector<int>& a) {
         int zero = 0;
         int n=a.size();
        int one = 0;
        int maxiContiZero =  0;
        
        for(int i=0; i<n; i++){
            if(a[i]==0)
                zero++;
            else{
                one++;
                zero--;
            }
            maxiContiZero = max(maxiContiZero,zero);
            if(zero<0)
                zero=0;
        }
        return maxiContiZero+one;
    }
};
```

## 🔹 Leetcode Mirror-Distance-Of-An-Integer
**Platform:** LeetCode

Problem Insight:
The problem requires finding the absolute difference between an integer and its digit-wise reverse. The "mirror distance" is defined as this absolute difference.

Approach:
The integer n is first converted into its string representation. This string is then reversed to obtain the reversed digit sequence. Finally, the reversed string is converted back to an integer, and the absolute difference between the original n and the reversed integer is returned.

Time Complexity:
O(log10 n)
Converting n to a string, reversing it, and converting back all take time proportional to the number of digits in n, which is log10 n.

Space Complexity:
O(log10 n)
Storing the string representation of n and its reversed version requires space proportional to the number of digits in n.

Optimization Notes:
The solution is optimal in terms of time complexity as any method to reverse an integer must process each of its digits. While it uses O(log10 n) space for string conversions, a purely mathematical approach could achieve O(1) auxiliary space, but the time complexity would remain the same. For Python, this string-based approach is often preferred for conciseness.

### 💻 Implementation
```py
class Solution:
    def mirrorDistance(self, n: int) -> int:
        return abs(n-int(str(n)[::-1]))
```
