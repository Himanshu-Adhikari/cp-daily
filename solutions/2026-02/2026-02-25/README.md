# 📅 Daily CP Solutions — 2026-02-25

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Longest Subarray With Majority Greater Than K
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks for the longest subarray where the count of elements greater than k is strictly larger than the count of elements less than or equal to k. This translates to finding the longest subarray with a strictly positive sum after transforming elements to +1 (if > k) and -1 (if <= k).

Approach:
The solution uses a prefix sum approach. It transforms array elements into +1 or -1 based on comparison with k, then calculates a running prefix sum. It finds the longest prefix subarray with a positive sum. For non-prefix subarrays, it specifically checks for those that yield a transformed sum of exactly 1.

Time Complexity: O(N)
Justification: The code iterates through the array once, and hash map operations (insert, count, access) take average O(1) time.

Space Complexity: O(N)
Justification: In the worst case, all prefix sums could be unique, requiring the hash map to store N entries.

Optimization Notes:
The solution is not generally correct or optimal for finding the longest subarray with a sum strictly greater than zero. While it finds prefix subarrays with positive sums and non-prefix subarrays with a sum of exactly 1, it fails to identify non-prefix subarrays with a sum greater than 1. A general solution would need to query for any previous prefix sum smaller than the current one, which an unordered map cannot do efficiently.

### 💻 Implementation
```cpp
int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        unordered_map<int,int>m;
        int sum = 0;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            
            if(arr[i]<=k)sum-=1;
            else sum+=1;
            
            if(sum>0)ans=i+1;
            else{
                int num = -((abs(sum)+1));
                if(m.count(num))ans = max(ans,i-m[num]);
            }
            
            if(m.count(sum)==0)m[sum]=i;
            
        }
        
        return ans;
    }
```

## 🔹 Leetcode 1356 Sort-Integers-By-The-Number-Of-1-Bits
**Platform:** LeetCode

Problem Insight:
The task is to sort an array of integers based on two criteria: primarily by their bit count in ascending order, and secondarily by their numerical value for numbers with the same bit count.

Approach:
The solution utilizes Python's built-in sort function with a custom key. The key for each element is a tuple consisting of its bit count and its value, allowing the sort to naturally handle the two-level comparison.

Time Complexity:
O(N log N)
Python's Timsort has an average and worst-case time complexity of O(N log N), and the bit_count() operation is very efficient.

Space Complexity:
O(N)
Python's Timsort algorithm requires O(N) auxiliary space in the worst case for its merging operations.

Optimization Notes:
This solution is optimal for a general sorting problem. Python's built-in sort is highly optimized, and the use of x.bit_count() provides an efficient, C-optimized way to calculate the number of set bits. There are no practical improvements for typical competitive programming constraints.

### 💻 Implementation
```py
class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        arr.sort(key=lambda x:(x.bit_count(),x))
        return arr
```
