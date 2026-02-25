# 📅 Daily CP Solutions — 2026-02-25

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Longest Subarray With Majority Greater Than K
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks for the longest subarray where the count of elements greater than 'k' strictly exceeds the count of elements less than or equal to 'k'. This is transformed into finding the longest subarray whose sum (after mapping elements > k to +1 and others to -1) is strictly positive.

Approach:
The solution transforms the input array into an array of +1s and -1s based on comparison with 'k'. It then calculates prefix sums. It records the first occurrence of each prefix sum in a hash map. The maximum length is updated if the current prefix sum is positive or if a previous prefix sum exists such that the subarray sum between them is exactly 1.

Time Complexity: O(N)
Justification: The code iterates through the array once, and hash map operations (insertion, lookup) take average O(1) time.

Space Complexity: O(N)
Justification: In the worst case, all prefix sums encountered can be distinct, requiring up to N entries in the hash map.

Optimization Notes:
The provided solution is not optimal for the general problem of finding the longest subarray with a strictly positive sum. While it correctly identifies positive-sum subarrays starting from index 0, and subarrays with a sum of exactly 1 (by checking for 'current_sum - 1' in the map), it fails to find subarrays whose sum is greater than 1 but do not start at index 0 and whose total prefix sum is currently non-positive. A more general approach for "longest subarray with sum > 0" is needed to cover all such cases.

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
The task is to sort an array of integers based on the number of set bits in their binary representation, using the original integer value as a tie-breaker.

Approach:
The solution uses Python's built-in sort with a custom key function. For each number, it generates a tuple (number_of_set_bits, number_itself), allowing the sort to naturally handle the two-level comparison criteria.

Time Complexity:
O(N log N)
Sorting N elements typically takes N log N comparisons, and counting bits for an integer (x.bit_count()) is an O(1) operation for fixed-size integers.

Space Complexity:
O(log N)
Python's Timsort (used by list.sort()) requires O(log N) auxiliary space for its merging operations.

Optimization Notes:
This solution is optimal for the given constraints. Sorting cannot be done faster than O(N log N) asymptotically, and the bit counting is highly efficient, often implemented as a hardware instruction.

### 💻 Implementation
```py
class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        arr.sort(key=lambda x:(x.bit_count(),x))
        return arr
```
