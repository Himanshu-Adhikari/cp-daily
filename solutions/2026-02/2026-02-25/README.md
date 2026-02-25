# 📅 Daily CP Solutions — 2026-02-25

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Longest Subarray With Majority Greater Than K
**Platform:** GeeksforGeeks

Problem Insight:
This problem transforms array elements to +1 (if arr[i] > k) or -1 (if arr[i] <= k) and aims to find the longest subarray where the sum of these transformed values is positive. It's a prefix sum variant.

Approach:
The solution uses prefix sums and an unordered_map to store the first occurrence of each prefix sum. It iterates through the array, updating the current prefix sum. If the current prefix sum is positive, the subarray from index 0 to the current index is a candidate. Otherwise, it checks if a previous prefix sum exists such that the subarray sum ending at the current index is exactly 1.

Time Complexity:
O(N)
The loop iterates N times, and hash map operations (insertions, lookups) take average O(1) time.

Space Complexity:
O(N)
In the worst case, all N prefix sums are distinct and stored in the hash map.

Optimization Notes:
This solution effectively finds the longest subarray where the sum of transformed elements is exactly 1, or where the sum from the beginning of the array is positive. While this is optimal for finding a sum of exactly 1, it might not be optimal for finding *any* sum strictly greater than 0 if the longest such subarray has a sum greater than 1 and does not start at index 0. A robust general solution for "longest subarray with sum strictly greater than 0" with varying (positive and negative) transformed elements typically involves a `std::map` (O(N log N)) or a specialized monotonic queue technique (O(N)) to efficiently find the earliest prefix sum less than the current one.

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
The task is to sort an array of integers primarily by their number of set bits (bit count), and secondarily by their numerical value if bit counts are identical.

Approach:
The solution uses Python's built-in sort with a custom key function. The key for each number is a tuple (its bit count, the number itself), which allows Python's tuple comparison to handle the multi-level sorting criteria directly.

Time Complexity:
O(N log N)
Sorting N elements with a comparison sort takes O(N log N) time, and bit_count operations are efficient (effectively O(1) for typical integer sizes).

Space Complexity:
O(N)
Python's Timsort, used by list.sort(), requires O(N) auxiliary space in the worst case.

Optimization Notes:
This solution is optimal for a comparison-based sort. It leverages Python's efficient built-in sorting algorithm and its native bit_count method, achieving the best possible asymptotic time complexity.

### 💻 Implementation
```py
class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        arr.sort(key=lambda x:(x.bit_count(),x))
        return arr
```
