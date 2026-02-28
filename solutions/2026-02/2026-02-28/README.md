# 📅 Daily CP Solutions — 2026-02-28

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Find The Closest Pair From Two Array To X
**Platform:** GeeksforGeeks

Problem Insight:
The problem aims to find a pair of numbers, one from each of two given arrays, whose sum is closest to a target value X. The arrays are assumed to be sorted.

Approach:
It employs a two-pointer technique with one pointer starting from the beginning of the first array and the other from the end of the second array. The pointers move inwards based on whether the current sum is less than or greater than the target, continuously updating the closest pair found so far.

Time Complexity: O(N+M)
Each pointer iterates through its respective array at most once, leading to a linear scan of both arrays.

Space Complexity: O(1)
Only a constant amount of extra space is used for storing pointers and the result variables, irrespective of input size.

Optimization Notes:
This solution is optimal given that the input arrays are already sorted. If the arrays were unsorted, an initial sorting step would be required, adding O(N log N + M log M) complexity.

### 💻 Implementation
```py
class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        vector<int>res;
        int n=arr1.size(),m=arr2.size();
        int i=0,j=m-1;
        int ni=-1,nj=-1;
        auto rec=[&](int k,int p){
          return abs(x-k-p);  
        };
        while(i<n and j>=0){
            if(ni==-1 or (rec(arr1[ni],arr2[nj])>rec(arr1[i],arr2[j]))){
                ni=i,nj=j;
            }
            if(arr1[i]+arr2[j]<x)i++;
            else j--;
        }
        return {arr1[ni],arr2[nj]}; 
    }
};
```

## 🔹 Leetcode Concatenation-Of-Consecutive-Binary-Numbers
**Platform:** LeetCode

Problem Insight:
The problem asks to concatenate binary representations of numbers 1 to n and return its decimal value modulo a given constant. The challenge is efficiently appending variable-length binary strings.

Approach:
The solution iteratively builds the concatenated value. For each number i, it calculates its bit length, then left-shifts the current result by that many bits, effectively making space. It then adds i to the shifted result to append its binary representation, all while applying modular arithmetic at each step.

Time Complexity:
O(n log n)
The loop runs n times. Inside, bit_length takes O(log i) time, dominating each O(1) bit shift, addition, and modulo operation.

Space Complexity:
O(1)
Only a few variables (result, MOD, i) are used, and the result is kept within modulo bounds, fitting in constant memory.

Optimization Notes:
The solution is optimal. Each number from 1 to n must be processed, and its binary length determined. The bitwise operations and modular arithmetic used are the most efficient way to simulate binary string concatenation and calculate the decimal value for numbers up to n, making O(n log n) the inherent lower bound.

### 💻 Implementation
```py
class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MOD = 1_000_000_007
        result = 0
        for i in range(1, n + 1):
            result = ((result << i.bit_length()) + i) % MOD

        return result
```
