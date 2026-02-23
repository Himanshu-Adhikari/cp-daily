# 📅 Daily CP Solutions — 2026-02-21

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Find H Index
**Platform:** GeeksforGeeks

Problem Insight:
The h-index has a monotonic property where if a value k is a valid h-index, any value less than k is also valid. This allows for binary search over the possible range of h-index values.

Approach:
The solution employs binary search over the potential h-index values, ranging from 0 to the maximum citation count. For each mid value, it counts papers having at least that many citations. The search range is adjusted based on whether the count meets the h-index criterion (count >= mid).

Time Complexity:
O(N * log(max_citation_value))
Binary search runs log(max_citation_value) times, and each iteration involves a linear scan of N citations.

Space Complexity:
O(1)
Only a constant number of variables are used regardless of input size.

Optimization Notes:
The solution is not optimal. An O(N) time complexity can be achieved using counting sort (also known as bucket sort) if citation values are bounded by N. Another common optimal approach involves sorting the citations first (O(N log N)) and then performing a linear scan or binary search on the sorted array in O(log N) or O(N) time, leading to a total O(N log N) complexity.

### 💻 Implementation
```py
class Solution:
    def hIndex(self, citations):
        l,h=0,max(citations)
        while(l<=h):
            m=(l+h)//2
            cnt=0
            for i in citations:
                if i>=m:
                    cnt+=1
            if(cnt>=m):l=m+1
            else:h=m-1
        return h
    
    
```

## 🔹 Leetcode Prime Number Of Set Bits In Binary Rep
**Platform:** LeetCode

Problem Insight:
The problem requires counting numbers within a given range whose binary representation has a number of set bits that is a prime number.

Approach:
The solution iterates through every integer in the specified range. For each number, it efficiently counts its set bits and checks if this count is one of the precomputed small prime numbers.

Time Complexity:
O(R - L + 1)
The loop runs (right - left + 1) times. The i.bit_count() operation and set lookup are effectively constant time for the given constraints.

Space Complexity:
O(1)
A fixed-size set of prime numbers is stored, consuming constant memory independent of the input range.

Optimization Notes:
The solution is optimal. It processes each number in the range once and uses highly efficient constant-time operations for bit counting and prime checking.

### 💻 Implementation
```py
class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        res=0
        s={2, 3, 5, 7, 11, 13, 17 , 19}
        for i in range(left,right+1):
            if(i.bit_count() in s):
                res+=1
        return res
```
