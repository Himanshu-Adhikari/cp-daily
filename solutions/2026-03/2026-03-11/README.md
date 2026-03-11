# 📅 Daily CP Solutions — 2026-03-11

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Sum Of Subarray Minimum
**Platform:** GeeksforGeeks

Problem Insight:
The sum of subarray minimums can be efficiently computed by considering each element's contribution as a minimum. This contribution depends on the number of subarrays for which it is the minimum.

Approach:
First, a monotonic stack is used to find the Previous Smaller Element (PSE) for each array element. Then, a dynamic programming approach calculates ans[i], which is the sum of minimums for all subarrays ending at index i, using arr[i] and the value ans[PSE_index] to build the result.

Time Complexity:
O(N)
Both the monotonic stack operation and the dynamic programming calculation iterate through the array once, resulting in linear time complexity.

Space Complexity:
O(N)
A stack and two auxiliary vectors of size N are used to store intermediate results.

Optimization Notes:
This solution is optimal. It achieves linear time complexity by processing each element at most a constant number of times, which is the best possible asymptotic complexity for this problem.

### 💻 Implementation
```cpp
class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
         int n = arr.size();
        stack<int>s;
        vector<int>v(n,-1);
        vector<int>ans(n,0);
        int temp = 0;
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>arr[i]){
                v[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        for(int i=0;i<n;i++){
            
            if(v[i]==-1){
                ans[i] = (i+1)*arr[i];
            }
            else{
                int k = i-v[i];
                ans[i]=arr[i]*k;
                ans[i]+=ans[v[i]];
            }
            
            temp+=ans[i];
        }
        
        return temp;
    
    }
};
```

## 🔹 Leetcode Complement-Of-Base-10-Integer
**Platform:** LeetCode

Problem Insight:
The task is to find the bitwise complement of a non-negative integer by flipping all bits in its binary representation. For example, the complement of 5 (101) is 2 (010).

Approach:
The solution converts the input integer to its binary string, removes the "0b" prefix, then iterates through this string to flip each '0' to '1' and '1' to '0'. Finally, it joins the flipped characters into a new binary string and converts it back to an integer.

Time Complexity:
O(log N) because string conversion and manipulation operations scale with the number of bits in N, which is log N.

Space Complexity:
O(log N) due to the creation of intermediate binary strings whose length is proportional to log N.

Optimization Notes:
This solution is not optimal for N > 0 as it involves multiple string conversions. A more efficient bitwise approach would be to find the smallest power of two greater than N (mask = (1 << N.bit_length()) - 1) and then compute N ^ mask. This alternative handles N=0 incorrectly and would require a special case for N=0.

### 💻 Implementation
```py
class Solution:
    def bitwiseComplement(self, n: int) -> int:
        return int(''.join('1' if i=='0' else '0' for i in bin(n)[2:]),2)
```
