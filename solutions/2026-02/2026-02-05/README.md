# 📅 Daily CP Solutions — 2026-02-05

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Maximize-Number-Of-1S
**Platform:** GeeksforGeeks

Problem Insight:
This problem asks for the maximum length of a contiguous subarray where the count of zeros is at most K. It's a classic example of a fixed-size or variable-size sliding window problem.

Approach:
The solution uses a two-pointer sliding window approach. The right pointer expands the window. If the number of zeros in the window exceeds K, the left pointer shrinks the window until the zero count is valid again. The maximum valid window length is tracked.

Time Complexity:
O(N) because both the left and right pointers traverse the array at most once.

Space Complexity:
O(1) because a constant number of variables are used for tracking pointers and counts.

Optimization Notes:
The solution is optimal. A sliding window achieves linear time complexity, which is the best possible as every element must be inspected at least once.

### 💻 Implementation
```cpp
class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int res=0;
        int i=0;
        int n=arr.size();
        int curr=0,j=0;
        while(i<n){
            if(arr[i]==0)curr+=1;
            while(curr>k and j<=i){
                if(arr[j]==0)curr-=1;
                j+=1;
            }
            res=max(res,i-j+1);
            i++;        
        }
        return res;
    }
};

```

## 🔹 Leetcode Transformed-Array
**Platform:** LeetCode

Problem Insight:
The problem defines a transformation on an array where each output element is derived from a circularly shifted index of the input array. The shift amount for each index depends on the value at that specific index in the input array.

Approach:
The solution iterates through the input array, calculating a specific circular shift for each position. For each index i, it computes a non-negative shift value based on nums[i] modulo array size, handling negative inputs and a special case for zero. It then copies the element from the original array at this new cyclically shifted index into the result array.

Time Complexity:
O(n)
The solution involves a single loop that iterates through all n elements of the input array, performing constant-time operations for each element.

Space Complexity:
O(n)
A new vector of size n is allocated to store the transformed array, requiring additional space proportional to the input size.

Optimization Notes:
The solution is optimal. O(n) time complexity is necessary as every element in the input array must be considered to produce the transformed output. O(n) space complexity is required to store and return the new transformed array.

### 💻 Implementation
```cpp
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            if(nums[i]==0)res[i]=0;
            else{
                int id = ((nums[i] > 0)?nums[i]:n+nums[i]%n)% n;
                res[i] = nums[(i + id) % n];
            }
        }
        return res;      
    }
};
```
