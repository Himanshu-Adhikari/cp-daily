# 📅 Daily CP Solutions — 2026-02-22

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Count Subarrays With Given Xor
**Platform:** GeeksforGeeks

Problem Insight:
This problem asks to count subarrays whose XOR sum is equal to a given target k. It's a classic prefix sum/XOR problem.

Approach:
Utilize prefix XOR sums and a hash map to efficiently count previous prefix XOR sums. Iterate through the array, maintain the current prefix XOR, and add occurrences of (current_xor ^ k) from the map to the result.

Time Complexity:
O(N log N)
The loop runs N times, and map operations (insert/lookup) take O(log N) time for std::map.

Space Complexity:
O(N)
The map stores up to N+1 distinct prefix XOR sums, consuming space proportional to N.

Optimization Notes:
The approach is optimal. For better average performance, std::unordered_map can be used instead of std::map to reduce map operations from O(log N) to O(1) on average, achieving O(N) average time complexity.

### 💻 Implementation
```cpp
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        #define ll long long
        ll res=0;
        map<ll,ll>m;
        ll curr=0;
        m[0]=1;
        for(int i:arr){
            curr^=i;
            res+=m[curr^k];
            m[curr]++;
        }
        return res;
    }
};
```

## 🔹 Leetcode 868 Binarygap
**Platform:** LeetCode

Problem Insight:
The core problem is to find the maximum distance between two '1' bits in the binary representation of an integer. This requires sequentially examining the bits.

Approach:
The solution first converts the input integer into its binary string representation. It then iterates through this string, tracking the index of the most recently seen '1' to calculate and update the maximum gap between consecutive '1's.

Time Complexity:
O(log n)
Converting the integer to its binary string takes O(log n) time, and iterating through this string also takes O(log n) time, where log n is the number of bits in n.

Space Complexity:
O(log n)
The binary string representation of 'n' needs O(log n) space to be stored.

Optimization Notes:
The approach is optimal in terms of time complexity. Space can be optimized to O(1) by using bit manipulation (right-shifting 'n' and checking the least significant bit) instead of explicitly converting to a string.

### 💻 Implementation
```py
class Solution:
    def binaryGap(self, n: int) -> int:
        a=bin(n)[2::]
        pr=-1
        res=0
        for i,v in enumerate(a):
            if(v=='1'):
                if(pr!=-1):res=max(res,i-pr)
                pr=i
        return res
```
